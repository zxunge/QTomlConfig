//# This file is a part of QTomlConfig and is subject to the the terms of the MIT license.
//# Copyright (c) zxunge <3396563372@qq.com>
//# See https://github.com/zxunge/QTomlConfig/blob/main/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#ifndef QTOMLCONFIG_CONFIG_H_
#define QTOMLCONFIG_CONFIG_H_

#include "error.h"
#include <QVariant>
#include <QFile>
#include <initializer_list>

namespace QTomlConfig : public QObject
{
    class ConfigItem
    {
    siganls:
        void errorReached(const Error &err);
        
    public:
        ConfigItem(const QString &key, const QVariant &val);
        bool check(const QVariant &val) const;
        
    private:
        QPair<QString, QVariant> m_cfgItem;
    };
    
    class ConfigGroup
    {
    private:
        QList<ConfigItem> m_group;
    
    public:
        ConfigGroup(std::initializer_list<ConfigItem> args);
    };
    
    class ConfigMgr : public QObject
    {
        Q_OBJECT
        
    siganls:
        void errorReached(const Error &err);
        
    public:
        ConfigMgr(const QString &filename);
        
    private:
        QFile m_file;
    };
}

#endif // QTOMLCONFIG_CONFIG_H_