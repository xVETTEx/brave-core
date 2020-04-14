/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <utility>

#include "bat/ledger/internal/request/request_util.h"
#include "brave/components/brave_rewards/browser/test/rewards_browsertest_responses.h" // NOLINT
#include "content/public/test/browser_test_utils.h"

namespace rewards_browsertest_utils {

std::unique_ptr<net::test_server::HttpResponse> HandleRequest(
    const net::test_server::HttpRequest& request) {
  std::unique_ptr<net::test_server::BasicHttpResponse> http_response(
      new net::test_server::BasicHttpResponse());
  http_response->set_code(net::HTTP_OK);
  http_response->set_content_type("text/html");

  if (request.relative_url == "/twitter") {
    http_response->set_content(
        "<html>"
        "  <head></head>"
        "  <body>"
        "    <div data-testid='tweet' data-tweet-id='123'>"
        "      <a href='/status/123'></a>"
        "      <div role='group'>Hello, Twitter!</div>"
        "    </div>"
        "  </body>"
        "</html>");
    return std::move(http_response);
  }

  if (request.relative_url == "/oldtwitter") {
    http_response->set_content(
        "<html>"
        "  <head></head>"
        "  <body>"
        "    <div class='tweet' data-tweet-id='123'>"
        "      <div class='js-actions'>Hello, Twitter!</div>"
        "    </div>"
        "  </body>"
        "</html>");
    return std::move(http_response);
  }

  if (request.relative_url == "/reddit") {
    http_response->set_content(
      "<html>"
        "  <head></head>"
        "  <body>"
        "    <div class='Comment'>"
        "      <div>"
        "        <button aria-label='more options'>"
        "        </button>"
        "      </div>"
        "    </div>"
        "  </body>"
        "</html>");
    return std::move(http_response);
  }

  if (request.relative_url == "/github") {
    http_response->set_content(
      "<html>"
        "  <head></head>"
        "  <body>"
        "   <div class='timeline-comment-actions'>"
        "     <div>GitHubCommentReactsButton</div>"
        "     <div>GitHubCommentElipsesButton</div>"
        "   </div>"
        " </body>"
        "</html>");
    return std::move(http_response);
  }

  http_response->set_content(
      "<html>"
      "  <head></head>"
      "  <body>"
      "    <div>Hello, world!</div>"
      "  </body>"
      "</html>");

  return std::move(http_response);
}

bool URLMatches(
    const std::string& url,
    const std::string& path,
    const std::string& prefix,
    const ServerTypes& server) {
  const std::string target_url =
      braveledger_request_util::BuildUrl(path, prefix, server);
  return (url.find(target_url) == 0);
}

std::string GetUpholdUser(bool wallet_verified) {
    const std::string verified = wallet_verified
        ? "2018-08-01T09:53:51.258Z"
        : "null";

    const std::string status = wallet_verified
        ? "ok"
        : "pending";

    const std::string name = "Test User";

    return base::StringPrintf(
      "{"
        "\"name\": \"%s\","
        "\"memberAt\": \"%s\","
        "\"status\": \"%s\","
        "\"currencies\": [\"BAT\"]"
      "}",
      name.c_str(),
      verified.c_str(),
      status.c_str());
  }

}  // namespace rewards_browsertest_utils
