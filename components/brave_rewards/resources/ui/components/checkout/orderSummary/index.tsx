/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

import * as React from 'react'

import { LocaleContext } from '../localeContext'

import {
  Container,
  Description,
  BatAmount,
  ExchangeAmount
} from './style'

interface OrderSummaryProps {
  description: string
  orderTotal: string
  orderTotalConverted: string
}

export function OrderSummary (props: OrderSummaryProps) {
  const locale = React.useContext(LocaleContext)
  return (
    <Container>
      <table>
        <thead>
          <tr>
            <th>{locale.get('itemSelected')}</th>
            <th>{locale.get('orderTotal')}</th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <td>
              <Description>{props.description}</Description>
            </td>
            <td>
              <BatAmount locale={locale}>{props.orderTotal}</BatAmount>
              <ExchangeAmount>{props.orderTotalConverted}</ExchangeAmount>
            </td>
          </tr>
        </tbody>
      </table>
    </Container>
  )
}
