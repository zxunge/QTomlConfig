//# This file is a part of QTomlConfig and is subject to the the terms of the MIT license.
//# Copyright (c) zxunge <3396563372@qq.com>
//# See https://github.com/zxunge/QTomlConfig/blob/main/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#ifndef QTOMLCONFIG_ERROR_H_
#define QTOMLCONFIG_ERROR_H_

#include <QObject>
#include <QPair>

namespace QTomlConfig
{
    enum class ErrCode { ERR_FILE_OPEN, 
                         ERR_TOML_SYNTAX_ERROR, 
                         ERR_USER_TYPE_INCORRECT };
                       
    typedef QPair<ErrCode, QString> Error;
    
    class ErrorHandler : public QObject
    {
        Q_OBJECT
        
    public slots:
        void addToErrorList(const Error &err);
    };
}

#endif // QTOMLCONFIG_ERROR_H_