/*
 * Copyright (C) 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "AGnssAidl"

#include "AGnss.h"
#include <inttypes.h>
#include <log/log.h>

namespace aidl::android::hardware::gnss {

std::shared_ptr<IAGnssCallback> AGnss::sCallback = nullptr;

ndk::ScopedAStatus AGnss::setCallback(const std::shared_ptr<IAGnssCallback>& callback) {
    ALOGD("AGnss::setCallback");
    std::unique_lock<std::mutex> lock(mMutex);
    sCallback = callback;
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus AGnss::setServer(AGnssType type, const std::string& hostname, int port) {
    ALOGD("AGnss::setServer: type: %s, hostname: %s, port: %d", toString(type).c_str(),
          hostname.c_str(), port);
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus AGnss::dataConnOpen(int64_t networkHandle, const std::string& apn,
                                       ApnIpType apnIpType) {
    ALOGD("AGnss::dataConnOpen: networkHandle:%" PRId64 ", apn: %s, apnIpType %s", networkHandle,
          apn.c_str(), toString(apnIpType).c_str());
    return ndk::ScopedAStatus::ok();
}

}  // namespace aidl::android::hardware::gnss
