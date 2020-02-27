/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

import * as React from 'react'
import { BatColorIcon, PlusIcon } from 'brave-ui/components/icons'
import { Button } from 'brave-ui/components'

import { FormSection } from '../formSection'

import {
  Content,
  WalletInfoPanel,
  ActionPanel,
  BatAmount,
  ExchangeAmount,
  LastUpdated,
  NotEnoughFunds,
  TermsOfSale
} from './style'

interface ActionButtonProps {
  onClick: () => void
}

function PayWithWalletButton (props: ActionButtonProps) {
  return (
    <Button
      text={'Pay with BAT'}
      size='medium'
      onClick={props.onClick}
      type='accent'
      brand='rewards'
    />
  )
}

function AddFundsButton (props: ActionButtonProps) {
  return (
    <Button
      text={'Add Funds'}
      size='medium'
      onClick={props.onClick}
      icon={{ image: <PlusIcon />, position: 'before' }}
      type='accent'
      brand='rewards'
    />
  )
}

interface UseWalletPanelProps {
  balance: string
  balanceConverted: string
  lastUpdated: string
  hasSufficientFunds?: boolean
  rewardsEnabled?: boolean
  walletVerified?: boolean
  onShowAddFunds: () => void
  onPayWithWallet: () => void
}

export function UseWalletPanel (props: UseWalletPanelProps) {
  if (!props.rewardsEnabled) {
    return null
  }

  return (
    <>
      <FormSection title={'Use your token balance'}>
        <Content>
          <WalletInfoPanel hasSufficientFunds={props.hasSufficientFunds}>
            <BatColorIcon />
            <BatAmount>{props.balance}</BatAmount>
            <ExchangeAmount>{props.balanceConverted}</ExchangeAmount>
            <LastUpdated>Updated {props.lastUpdated}</LastUpdated>
          </WalletInfoPanel>
          <ActionPanel>
            {
              props.hasSufficientFunds
                ? <PayWithWalletButton onClick={props.onPayWithWallet} />
                : props.walletVerified
                  ? <AddFundsButton onClick={props.onShowAddFunds} />
                  : <NotEnoughFunds>You don't have enough tokens to buy this item.</NotEnoughFunds>
            }
          </ActionPanel>
        </Content>
      </FormSection>
      {
        props.hasSufficientFunds &&
          <TermsOfSale>
            By clicking Pay with BAT, you agree to <a href='javascript:void 0'>Brave’s Terms of Sale</a>.
          </TermsOfSale>
      }
    </>
  )
}
