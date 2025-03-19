//# This file is a part of QTomlConfig and is subject to the the terms of the MIT license.
//# Copyright (c) zxunge <3396563372@qq.com>
//# See https://github.com/zxunge/QTomlConfig/blob/main/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#include "config.h"

namespace QTomlConfig
{
    
ErrorHandler errors;

ConfigItem::ConfigItem(const QString &key, const QVariant &val)
{
    connect(this, &errorReached, &errors, &Error::addToErrorList);
    if (!check(val))
        errorReached(Error(ErrCode::ERR_USER_TYPE_INCORRECT, tr(__FILE__ __LINE__ Q_FUNC_INFO "Unsupported initial item type.")));
    else
    
}

}