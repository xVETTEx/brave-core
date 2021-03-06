/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_CONFIRMATIONS_INTERNAL_STATIC_VALUES_H_
#define BAT_CONFIRMATIONS_INTERNAL_STATIC_VALUES_H_

#include <stdint.h>
#include <map>
#include <string>

#include "base/time/time.h"

namespace confirmations {

#define BAT_ADS_PRODUCTION_SERVER "https://ads-serve.brave.com"
#define BAT_ADS_STAGING_SERVER "https://ads-serve.bravesoftware.com"
#define BAT_ADS_DEVELOPMENT_SERVER "https://ads-serve.brave.software"

#define PROMOTION_STAGING_SERVER "https://grant.rewards.bravesoftware.com"
#define PROMOTION_PRODUCTION_SERVER "https://grant.rewards.brave.com"
#define PROMOTION_DEVELOPMENT_SERVER "https://grant.rewards.brave.software"

const int kNextPaymentDay = 5;

const int kMinimumUnblindedTokens = 20;
const int kMaximumUnblindedTokens = 50;

const uint64_t kNextTokenRedemptionAfterSeconds =
    24 * base::Time::kSecondsPerHour;
const uint64_t kDebugNextTokenRedemptionAfterSeconds =
    25 * base::Time::kSecondsPerMinute;

const uint64_t kRetryRefillTokensAfterSeconds = 15;

const uint64_t kRetryPayoutTokensAfterSeconds =
    1 * base::Time::kSecondsPerMinute;

const uint64_t kRetryAdsRewardsAfterSeconds =
    1 * base::Time::kSecondsPerMinute;

const uint64_t kRetryFailedConfirmationsAfterSeconds =
    5 * base::Time::kSecondsPerMinute;

}  // namespace confirmations

#endif  // BAT_CONFIRMATIONS_INTERNAL_STATIC_VALUES_H_
