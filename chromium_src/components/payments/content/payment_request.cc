/* Copyright 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#define BRAVE_PAYMENT_REQUEST_SET_OTHER_METHOD_TYPE \
    spec_->payment_method_identifiers_set().count("bat") || \

#include "../../../../../components/payments/content/payment_request.cc"

#undef BRAVE_PAYMENT_REQUEST_SET_OTHER_METHOD_TYPE
