//# This file is a part of QTomlConfig and is subject to the the terms of the MIT license.
//# Copyright (c) zxunge <3396563372@qq.com>
//# See https://github.com/zxunge/QTomlConfig/blob/main/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#ifndef QTOMLCONFIG_ERROR_H_
#define QTOMLCONFIG_ERROR_H_

#include <QObject>
#include <QString>
#include <QPair>
#include <QList>

namespace QTomlConfig
{
    // These types hold the errors thrown by QTomlConfig itself, not toml++ (the parser).
    enum class ErrCode { ERR_FILE_OPEN, 
                         ERR_FILE_NOT_EXISTING,
                         ERR_USER_TYPE_INCORRECT };
                       
    typedef QPair<ErrCode, QString> Error;
    constexpr auto NoError { Error() };
    
    class ErrorHandler : public QObject
    {
        Q_OBJECT
        
    public slots:
        void addToErrorList(const Error &err);
        
    public:
        QList<Error> getAllErrors() const;
        Error getLastError() const;
        
    private:
        QList<Error> m_errorList;
    };
}

#endif // QTOMLCONFIG_ERROR_H_