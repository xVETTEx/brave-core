/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_REWARDS_BROWSER_REWARDS_BROWSERTEST_UTILS_H_
#define BRAVE_COMPONENTS_BRAVE_REWARDS_BROWSER_REWARDS_BROWSERTEST_UTILS_H_

#include <string>

namespace rewards_browsertest_utils {

enum class ContributionType { OneTimeTip, MonthlyTip };

bool URLMatches(
    const std::string& url,
    const std::string& path,
    const std::string& prefix,
    const ServerTypes& server);

}  // namespace rewards_browsertest_utils

#endif  // BRAVE_COMPONENTS_BRAVE_REWARDS_BROWSER_REWARDS_BROWSERTEST_UTILS_H_
