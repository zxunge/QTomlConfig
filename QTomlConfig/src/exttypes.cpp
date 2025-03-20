//# This file is a part of QTomlConfig and is subject to the the terms of the MIT license.
//# Copyright (c) zxunge <3396563372@qq.com>
//# See https://github.com/zxunge/QTomlConfig/blob/main/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#include "exttypes.h"

// -------------Implementation of Array-----------------
Array::Array(std::initializer_list<QVariant> args)
{
    for (auto v : args)
    {
        if (!ConfigItem::check(v))
            emit errorReached(Error(ErrCode::ERR_USER_TYPE_INCORRECT, tr(__FILE__ __LINE__ Q_FUNC_INFO "Unsupported initial item type.")));
        else
            m_arr.push_back(v);
    }
}

// -------------Implementation of InlTable-----------------
InlTable::InlTable(const ConfigTable &tbl)
{
    for (auto i : tbl.getAllItems())
        m_tbl.push_back(i);
}

InlTable::InlTable(std::initializer_list<ConfigItem> args)
{
    for (auto i : args)
        m_tbl.push_back(i);
}