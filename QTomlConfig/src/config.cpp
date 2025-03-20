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
    connect(this, &ConfigItem::errorReached, &errors, &ErrorHandler::addToErrorList);
    if (!ConfigItem::check(val))
        emit errorReached(Error(ErrCode::ERR_USER_TYPE_INCORRECT, QString(__FILE__) + __LINE__ + Q_FUNC_INFO + tr("Unsupported initial item type.")));
    else
        m_cfgItem = QPair<QString, QVariant>(key, val);
}

// Checks if the provided value belongs to the native formats of TOML.
// https://toml.io/en/v1.0.0#keyvalue-pair
/* static */ bool ConfigItem::check(const QVariant &val)
{
    switch (val.
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
                typeId()
#else
                type()
#endif
    )
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

// -------------Implementation of ConfigTable-----------------
ConfigTable::ConfigTable(const QString &name, std::initializer_list<ConfigItem> args)
{
    for (const auto &item : args) 
        m_table.push_back(item);
    m_name = name;
}

ConfigItem ConfigTable::operator[](const QString &key) const
{
    for (const auto &t : m_table)
        if (t.key() == key)
            return t;
    return ConfigItem();
}

// -------------Implementation of ConfigMgr-----------------
ConfigMgr::ConfigMgr(const QString &filename)
{
    connect(this, &ConfigMgr::errorReached, &errors, &ErrorHandler::addToErrorList);
    
    m_file.setFileName(filename);
    if (!m_file.exists())
        emit errorReached(Error(ErrCode::ERR_FILE_NOT_EXISTING, QString(__FILE__) + __LINE__ + Q_FUNC_INFO + tr("Not an existing file.")));
    else if (!m_file.open(QIODevice::ReadWrite))
        emit errorReached(Error(ErrCode::ERR_FILE_OPEN, QString(__FILE__) + __LINE__ + Q_FUNC_INFO + tr("Unable to open file.")));
    else
        m_result = toml::parse(m_file.readAll().toStdString());
}

void ConfigMgr::add(const ConfigTable &table)
{
    
}

void ConfigMgr::add(const ConfigTable &table, const ConfigItem &item)
{
    
}

void ConfigMgr::add(const ConfigTable &table, const QString &key, const QVariant &val)
{
    
}

void ConfigMgr::add(const QString &table, const QString &key, const QVariant &val)
{
    
}

ConfigTable ConfigMgr::operator[](const QString &name) const
{
    
}

}