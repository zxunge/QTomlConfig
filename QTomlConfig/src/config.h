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
#include <toml++/toml.hpp>

namespace QTomlConfig
{
    class ConfigItem
    {
    siganls:
        void errorReached(const Error &err);
        
    public:
        ConfigItem(const QString &key, const QVariant &val);
        static bool check(const QVariant &val) const;
        operator QVariant() const { return m_cfgItem.second; }
        
    private:
        QPair<QString, QVariant> m_cfgItem;
    };
    
    class ConfigTable
    {
    private:
        QList<ConfigItem> m_table;
        QString m_name;
    
    public:
        ConfigTable(const QString &name, std::initializer_list<ConfigItem> args);
        ConfigItem operator[](const QString &key) const;
    };
    
    class ConfigMgr : public QObject
    {
        Q_OBJECT
        
    siganls:
        void errorReached(const Error &err);
        
    public:
        ConfigMgr(const QString &filename);
        void add(const ConfigTable &table);
        void add(const ConfigTable &table, const ConfigItem &item);
        void add(const ConfigTable &table, const QString &key, const QVariant &val);
        void add(const QString &table, const QString &key, const QVariant &val);
        ConfigTable operator[](const QString &name) const;
        
    private:
        QFile m_file;
        toml::table m_table;
    };
}

#endif // QTOMLCONFIG_CONFIG_H_