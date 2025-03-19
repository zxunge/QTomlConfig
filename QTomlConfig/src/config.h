//# This file is a part of QTomlConfig and is subject to the the terms of the MIT license.
//# Copyright (c) zxunge <3396563372@qq.com>
//# See https://github.com/zxunge/QTomlConfig/blob/main/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#ifndef QTOMLCONFIG_CONFIG_H_
#define QTOMLCONFIG_CONFIG_H_

#include "error.h"
#include <QString>
#include <QVariant>

namespace QTomlConfig : public QObject
{
    class ConfigGroup
    {
        
    };
    
    class ConfigItem
    {
    siganls:
        void errorReached(const TCFGError &err);
        
    public:
        ConfigItem(const QString &key, const QVariant &val);
    };
    
    class ConfigMgr
    {
        Q_OBJECT
        
    siganls:
        void errorReached(const TCFGError &err);
        
    public:
        ConfigMgr();
    };
}

#endif // QTOMLCONFIG_CONFIG_H_