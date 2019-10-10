/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

package org.chromium.chrome.browser.services;

import android.annotation.SuppressLint;
import android.util.Log;

import org.chromium.base.ApplicationStatus.ApplicationStateListener;
import org.chromium.base.ThreadUtils;

/**
* Brave's override for GoogleServicesManager, empty implementation.
*/

public class BraveOvrGoogleServicesManager implements ApplicationStateListener {

  private static final String TAG = "BraveOvrGoogleServicesManager";

  @SuppressLint("StaticFieldLeak")
  private static BraveOvrGoogleServicesManager sBraveOvrGoogleServicesManager;

  public static BraveOvrGoogleServicesManager get() {
      ThreadUtils.assertOnUiThread();
      if (sBraveOvrGoogleServicesManager == null) {
          sBraveOvrGoogleServicesManager = new BraveOvrGoogleServicesManager();
      }
      return sBraveOvrGoogleServicesManager;
  }

  public BraveOvrGoogleServicesManager() {
  }

  public void onMainActivityStart() {
  }

  @Override
  public void onApplicationStateChange(int newState) {
  }
}
