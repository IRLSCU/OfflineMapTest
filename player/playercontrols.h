﻿/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef PLAYERCONTROLS_H
#define PLAYERCONTROLS_H

#include <QMediaPlayer>
#include <QWidget>
#include "QtAV/AVPlayer.h"
QT_BEGIN_NAMESPACE
class QAbstractButton;
class QAbstractSlider;
class QComboBox;
QT_END_NAMESPACE

class PlayerControls : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerControls(QWidget *parent = nullptr);
    //记录当前的播放状态
    QtAV::AVPlayer::State state() const;
    int volume() const;
    bool isMuted() const;
    qreal playbackRate() const;

public slots:
    void setState(QtAV::AVPlayer::State state);
    void setVolume(int volume);
    void setMuted(bool muted);
    void setPlaybackRate(float rate);

signals:
    void play();
    void pause();
    void stop();
    void next();
    void previous();
    void changeVolume(int volume);
    void changeMuting(bool muting);
    void changeRate(qreal rate);

private slots:
    void playClicked();
    void muteClicked();
    void updateRate();
    void onVolumeSliderValueChanged();

private:
    QtAV::AVPlayer::State m_playerState = QtAV::AVPlayer::State::StoppedState;
    bool m_playerMuted = false;
    QAbstractButton *m_playButton = nullptr;//播放按钮
    QAbstractButton *m_stopButton = nullptr;//停止按钮
    QAbstractButton *m_nextButton = nullptr;//播放下一个
    QAbstractButton *m_previousButton = nullptr;//播放前一个
    QAbstractButton *m_muteButton = nullptr;//声音按钮
    QAbstractSlider *m_volumeSlider = nullptr;//声音滑块
    QComboBox *m_rateBox = nullptr;//播放速度模块
};

#endif // PLAYERCONTROLS_H
