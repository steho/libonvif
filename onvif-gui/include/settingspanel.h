/*******************************************************************************
* settingspanel.h
*
* Copyright (c) 2022 Stephen Rhodes
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*
*******************************************************************************/

#ifndef SETTINGSPANEL_H
#define SETTINGSPANEL_H

#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QGroupBox>
#include <QRadioButton>
#include <QMainWindow>
#include <QListWidget>

class SettingsPanel : public QWidget
{
    Q_OBJECT

public:
    SettingsPanel(QMainWindow *parent);
    void getActiveNetworkInterfaces();
    void getCurrentlySelectedIP(char *buffer);

    QMainWindow *mainWindow;
    QCheckBox *autoDiscovery;
    QPushButton *style;
    QPushButton *clear;
    QLineEdit *commonUsername;
    QLineEdit *commonPassword;
    QCheckBox *lowLatency;
    QCheckBox *hideToolTips;
    QComboBox *hardwareDecoders;
    QRadioButton *generateFilename;
    QRadioButton *defaultFilename;
    QCheckBox *disableAudio;
    QSlider *zoom;
    QSlider *panX;
    QSlider *panY;
    QPushButton *reset;
    QListWidget *interfaces;
    QComboBox *networkInterfaces;
    QSpinBox *keyframeCount;
    QLabel *lblKeyframeCount;

    QStringList decoders;
    QListWidget *listDecoders;
    QLabel *lblDecoders;

    const QString usernameKey   = "SettingsPanel/username";
    const QString passwordKey   = "SettingsPanel/password";
    const QString playerKey     = "SettingsPanel/player";
    const QString autoDiscKey   = "SettingsPanel/autoDiscovery";
    const QString multiBroadKey = "SettingsPanel/multiBroadcast";
    const QString broadRepKey   = "SettingsPanel/brodacastRepeat";
    const QString lowLatencyKey = "SettingsPanel/lowLatency";
    const QString decoderKey    = "SettingsPanel/decoder";
    const QString netIntfKey    = "SettingsPanel/networkInterface";
    const QString genFileKey    = "SettingsPanel/generateFIlename";
    const QString defFileKey    = "SettingsPanel/defaultFilename";
    const QString disAudioKey   = "SettingsPanel/disableAudio";
    const QString keyCountKey   = "SettingsPanel/keyframeCount";
    const QString hideTipsKey   = "SettingsPanel/hideToolTips";

signals:
    void msg(const QString&);

public slots:
    void usernameUpdated();
    void passwordUpdated();
    void autoDiscoveryClicked(bool);
    void lowLatencyClicked();
    void hideToolTipsClicked();
    void decoderChanged(const QString&);
    void zoomMoved(int);
    void panXMoved(int);
    void panYMoved(int);
    void resetClicked();
    void styleClicked();
    void clearClicked();
    void generateFilenameClicked(bool);
    void defaultFilenameClicked(bool);
    void disableAudioClicked(bool);
    void netIntfChanged(const QString&);
    void keyframeCountChanged(int);

};

#endif // SETTINGSPANEL_H