//# This file is a part of QTomlConfig and is subject to the the terms of the MIT license.
//# Copyright (c) zxunge <3396563372@qq.com>
//# See https://github.com/zxunge/QTomlConfig/blob/main/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#include "exttypes.h"

namespace QTomlConfig
{
    
// -------------Implementation of Array-----------------
Array::Array(std::initializer_list<QVariant> args)
{
    connect(this, &Array::errorReached, &errors, &ErrorHandler::addToErrorList);
    
    for (const auto &v : args)
    {
        if (!ConfigItem::check(v))
            emit errorReached(Error(ErrCode::ERR_USER_TYPE_INCORRECT, QString(__FILE__) + __LINE__ + Q_FUNC_INFO + tr("Unsupported initial item type.")));
        else
            m_arr.push_back(v);
    }
}

// -------------Implementation of InlTable-----------------
InlTable::InlTable(const ConfigTable &tbl)
{
    for (const auto &i : tbl.getAllItems())
        m_tbl.push_back(i);
}

InlTable::InlTable(std::initializer_list<ConfigItem> args)
{
    for (const auto &i : args)
        m_tbl.push_back(i);
}

}