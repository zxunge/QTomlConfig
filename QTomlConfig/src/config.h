//# This file is a part of QTomlConfig and is subject to the the terms of the MIT license.
//# Copyright (c) zxunge <3396563372@qq.com>
//# See https://github.com/zxunge/QTomlConfig/blob/main/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#ifndef QTOMLCONFIG_CONFIG_H_
#define QTOMLCONFIG_CONFIG_H_

#include "error.h"

namespace QTomlConfig : public QObject
{
    class ConfigGroup
    {
        
    };
    
    class ConfigMgr
    {
        Q_OBJECT
        
    siganls:
        void errorReached(const TCFGError err);
        
    public:
        ConfigMgr();
    };
}

#endif // QTOMLCONFIG_CONFIG_H_