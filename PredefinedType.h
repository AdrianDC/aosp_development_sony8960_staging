/*
 * Copyright (C) 2016 The Android Open Source Project
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

#ifndef PREDEFINED_TYPE_H_

#define PREDEFINED_TYPE_H_

#include "Type.h"

namespace android {

struct PredefinedType : public Type {
    PredefinedType(const char *name);

    std::string getCppType(StorageMode mode,
                           std::string *extra,
                           bool specifyNamespaces) const override;
    std::string getJavaType() const override;

    void emitReaderWriter(
            Formatter &out,
            const std::string &name,
            const std::string &parcelObj,
            bool parcelObjIsPointer,
            bool isReader,
            ErrorMode mode) const override;

    void emitReaderWriterEmbedded(
            Formatter &out,
            const std::string &name,
            bool nameIsPointer,
            const std::string &parcelObj,
            bool parcelObjIsPointer,
            bool isReader,
            ErrorMode mode,
            const std::string &parentName,
            const std::string &offsetText) const override;

    bool isJavaCompatible() const override;

    bool needsEmbeddedReadWrite() const override;
    bool resultNeedsDeref() const override;

private:
    std::string mName;

    DISALLOW_COPY_AND_ASSIGN(PredefinedType);
};

}  // namespace android

#endif  // PREDEFINED_TYPE_H_
