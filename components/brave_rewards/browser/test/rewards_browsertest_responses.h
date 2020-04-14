/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_REWARDS_BROWSER_REWARDS_BROWSERTEST_RESPONSES_H_
#define BRAVE_COMPONENTS_BRAVE_REWARDS_BROWSER_REWARDS_BROWSERTEST_RESPONSES_H_

#include <memory>
#include <string>

#include "net/test/embedded_test_server/http_request.h"
#include "net/test/embedded_test_server/http_response.h"

namespace rewards_browsertest_utils {

std::unique_ptr<net::test_server::HttpResponse> HandleRequest(
    const net::test_server::HttpRequest& request);

std::string GetUpholdUser(bool wallet_verified);

}  // namespace rewards_browsertest_utils

#endif  // BRAVE_COMPONENTS_BRAVE_REWARDS_BROWSER_REWARDS_BROWSERTEST_RESPONSES_H_
