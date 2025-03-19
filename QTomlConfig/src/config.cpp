//# This file is a part of QTomlConfig and is subject to the the terms of the MIT license.
//# Copyright (c) zxunge <3396563372@qq.com>
//# See https://github.com/zxunge/QTomlConfig/blob/main/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#include "config.h"
#include <QMetaType>

namespace QTomlConfig
{
    
ErrorHandler errors;

// -------------Implementation of ConfigItem-----------------
ConfigItem::ConfigItem(const QString &key, const QVariant &val)
{
    connect(this, &errorReached, &errors, &Error::addToErrorList);
    if (!check(val))
        emit errorReached(Error(ErrCode::ERR_USER_TYPE_INCORRECT, tr(__FILE__ __LINE__ Q_FUNC_INFO "Unsupported initial item type.")));
    else
        m_cfgItem = QPair<QString, QVariant>(key, val);
}

// Checks if the provided value belongs to the native formats of TOML.
// https://toml.io/en/v1.0.0#keyvalue-pair
bool ConfigItem::check(const QVariant &val) const
{
    switch (val.type())
    {
    case QMetaType::QVariantList:
    case QMetaType::QString:
    case QMetaType::Int:
    case QMetaType::Double:
    case QMetaType::Bool:
    case QMetaType::QDateTime:
    case QMetaType::QDate:
    case QMetaType::QTime:
    // "Offset Date-Time" is not supported...
        return true;
    
    default:
        return false;
    }
}

// -------------Implementation of ConfigGroup-----------------
ConfigGroup::ConfigGroup(std::initializer_list<ConfigItem> args)
{
    for (auto item : args) 
        m_group.push_back(item);
}

}