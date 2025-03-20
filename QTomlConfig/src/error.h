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
    enum class ErrCode { ERR_FILE_OPEN, 
                         ERR_FILE_NOT_EXISTING,
                         ERR_USER_TYPE_INCORRECT,
                         ERR_TOML_SYNTAX };
                       
    typedef QPair<ErrCode, QString> Error;
    const auto NoError { Error() };        // Identifier for no errors.
    
    class ErrorHandler : public QObject
    {
        Q_OBJECT
        
    public slots:
        void addToErrorList(const Error &err);
        
    public:
        QList<Error> getAllErrors() const;
        Error getLastError();
        
    private:
        QList<Error> m_errorList;
    };
    extern ErrorHandler errors;
}

#endif // QTOMLCONFIG_ERROR_H_