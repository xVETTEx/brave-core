/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

import * as React from 'react'

import { LocaleContext } from '../localeContext'
import { Container, ImageContainer, TextContainer } from './style'
import batReferSrc from './assets/bat_refer.svg'

export function PaymentComplete (props: {}) {
  const locale = React.useContext(LocaleContext)
  return (
    <Container>
      <ImageContainer><img src={batReferSrc} /></ImageContainer>
      <TextContainer>
        <h2>{locale.get('goodToGo')}</h2>
        <p>{locale.get('enjoyYourPurchase')}</p>
      </TextContainer>
    </Container>
  )
}
