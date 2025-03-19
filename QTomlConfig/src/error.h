//# This file is a part of QTomlConfig and is subject to the the terms of the MIT license.
//# Copyright (c) zxunge <3396563372@qq.com>
//# See https://github.com/zxunge/QTomlConfig/blob/main/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#ifndef QTOMLCONFIG_ERROR_H_
#define QTOMLCONFIG_ERROR_H_

#include <QObject>
#include <QMap>

namespace QTomlConfig
{
    enum class ErrCode {  };
    typedef QMap<ErrCode, QString> TCFGError;
    class Error : public QObject
    {
        Q_OBJECT
        
    public slots:
        void addToErrorList(const TCFGError &err);
    };
}

#endif // QTOMLCONFIG_ERROR_H_