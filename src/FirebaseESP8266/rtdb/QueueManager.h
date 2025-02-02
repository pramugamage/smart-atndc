/**
 * Google's Firebase QueueManager class, QueueManager.h version 1.0.4
 *
 * This library supports Espressif ESP8266 and ESP32
 *
 * Created February 28, 2022
 *
 * This work is a part of Firebase ESP Client library
 * Copyright (c) 2022 K. Suwatchai (Mobizt)
 *
 * The MIT License (MIT)
 * Copyright (c) 2022 K. Suwatchai (Mobizt)
 *
 *
 * Permission is hereby granted, free of charge, to any person returning a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "../FirebaseFS.h"

#ifdef ENABLE_RTDB

#ifndef FIREBASE_QUEUE_MANAGER_H
#define FIREBASE_QUEUE_MANAGER_H
#include <Arduino.h>
#include "../FB_Utils.h"
#include "QueueInfo.h"

class QueueManager
{
    friend class FB_RTDB;
    friend class FirebaseData;

public:
    QueueManager();
    ~QueueManager();

    bool add(QueueItem q);
    void remove(uint8_t index);
    size_t size();

private:
    void clear();
    MB_VECTOR<struct QueueItem> *_queueCollection = nullptr;
    uint8_t _maxQueue = 10;
};

#endif

#endif // ENABLE