//# This file is a part of QTomlConfig and is subject to the the terms of the MIT license.
//# Copyright (c) zxunge <3396563372@qq.com>
//# See https://github.com/zxunge/QTomlConfig/blob/main/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#ifndef QTOMLCONFIG_EXTTYPES_H_
#define QTOMLCONFIG_EXTTYPES_H_

#include "error.h"
#include "config.h"

namespace QTomlConfig
{
    class Array : public QObject
    {
        Q_OBJECT
        
    signals:
        void errorReached(const Error &err);
    
    public:
        Array(std::initializer_list<QVariant> args);
    
    private:
        QVariantList m_arr;
    };
    
    class InlTable : public QObject
    {
        Q_OBJECT
        
    public:
        InlTable(const ConfigTable &tbl);
        InlTable(std::initializer_list<ConfigItem> args);
        
    private:
        QList<ConfigItem> m_tbl;
    };
}

#endif // QTOMLCONFIG_EXTTYPES_H_