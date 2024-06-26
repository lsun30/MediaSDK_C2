// Copyright (c) 2017-2023 Intel Corporation
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <string>
#include <map>
#include <mutex>
#include "mfx_defs.h"

class MfxC2ComponentsMonitor
{
private:
    MfxC2ComponentsMonitor() {}
public:
    MFX_CLASS_NO_COPY(MfxC2ComponentsMonitor);

    static MfxC2ComponentsMonitor& getInstance()
    {
        static MfxC2ComponentsMonitor m_pInstance;
        return m_pInstance;
    }

    unsigned int get(std::string name);
    void increase(std::string name);
    void decrease(std::string name);

private:
    std::map<std::string, unsigned int> m_monitor;
    std::mutex m_mutex;
};
