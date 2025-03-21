//# This file is a part of QTomlConfig and is subject to the the terms of the MIT license.
//# Copyright (c) zxunge <3396563372@qq.com>
//# See https://github.com/zxunge/QTomlConfig/blob/main/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#include "error.h"

namespace QTomlConfig
{

void ErrorHandler::addToErrorList(const Error &err)
{
    m_errorList.push_back(err);
}

QList<Error> ErrorHandler::getAllErrors() const
{
    return m_errorList;
}

Error ErrorHandler::getLastError() const
{
    if (m_errorList.isEmpty())
        return NoError;
    else
        return m_errorList.last();
}

}