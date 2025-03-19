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
    if (!ConfigItem::check(val))
        emit errorReached(Error(ErrCode::ERR_USER_TYPE_INCORRECT, tr(__FILE__ __LINE__ Q_FUNC_INFO "Unsupported initial item type.")));
    else
        m_cfgItem = QPair<QString, QVariant>(key, val);
}

// Checks if the provided value belongs to the native formats of TOML.
// https://toml.io/en/v1.0.0#keyvalue-pair
/* static */ bool ConfigItem::check(const QVariant &val) const
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
ConfigTable::ConfigTable(const QString &name, std::initializer_list<ConfigItem> args)
{
    for (auto item : args) 
        m_group.push_back(item);
    m_name = name;
}

// -------------Implementation of ConfigMgr-----------------
ConfigMgr::ConfigMgr(const QString &filename)
{
    m_file.setFileName(filename);
    if (!m_file.exists())
        emit errorReached(Error(ERR_FILE_NOT_EXISTING, tr(__FILE__ __LINE__ Q_FUNC_INFO "Not an existing file.")));
    else if (!m_file.open(QIODevice::ReadWrite))
        emit errorReached(Error(ERR_FILE_OPEN, tr(__FILE__ __LINE__ Q_FUNC_INFO "Unable to open file.")));
    else
        m_table = toml::parse(m_file.readAll().toStdString());
}

void add(const ConfigTable &table)
{
    
}

void add(const ConfigTable &table, const ConfigItem &item)
{
    
}

void add(const ConfigTable &table, const QString &key, const QVariant &val)
{
    
}

void add(const QString &table, const QString &key, const QVariant &val)
{
    
}

ConfigTable operator[](const QString &name) const
{
    
}

}