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

package android.hardware.gnss;

import android.hardware.gnss.GnssLocation;

/**
 * The callback interface to report batched GNSS locations from the HAL.
 *
 * @hide
 */
@VintfStability
interface IGnssBatchingCallback {
    /**
     * Called when a batch of locations is output, by various means, including
     * a flush request, as well as the buffer becoming full (if appropriate option
     * is set.)
     *
     * All locations returned by this callback must be cleared from the hardware
     * buffer, such the sequential calls of this callback do not return any
     * redundant locations.  (Same lat/lon, at a new time, is acceptable.)
     *
     * @param locations A list of GNSS Locations
     */
    void gnssLocationBatchCb(in GnssLocation[] locations);
}
