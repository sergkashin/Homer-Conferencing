/*****************************************************************************
 *
 * Copyright (C) 2010 Thomas Volkert <thomas@homer-conferencing.com>
 *
 * This software is free software.
 * Your are allowed to redistribute it and/or modify it under the terms of
 * the GNU General Public License version 2 as published by the Free Software
 * Foundation.
 *
 * This source is published in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License version 2 for more details.
 *
 * You should have received a copy of the GNU General Public License version 2
 * along with this program. Otherwise, you can write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111, USA.
 * Alternatively, you find an online version of the license text under
 * http://www.gnu.org/licenses/gpl-2.0.html.
 *
 *****************************************************************************/

/*
 * Purpose: Dialog for configuration edit
 * Since:   2010-10-03
 */

#ifndef _PREFERENCES_DIALOG_
#define _PREFERENCES_DIALOG_

#include <AudioPlayback.h>
#include <ui_ConfigurationDialog.h>

#include <Widgets/VideoWidget.h>
#include <Widgets/AudioWidget.h>
#include <WaveOut.h>

#include <QCloseEvent>
#include <QNetworkAccessManager>
#include <QStringList>

namespace Homer { namespace Gui {

using namespace Homer::Multimedia;

///////////////////////////////////////////////////////////////////////////////

class ConfigurationDialog :
    public QDialog,
    AudioPlayback,
    public Ui_ConfigurationDialog
{
    Q_OBJECT;
public:
    /// The default constructor
    ConfigurationDialog(QWidget* pParent, std::list<std::string>  pLocalAdresses, VideoWorkerThread* pVideoWorker, AudioWorkerThread* pAudioWorker);

    /// The destructor.
    virtual ~ConfigurationDialog();

public slots:
    int exec();

private slots:
    void ShowVideoSourceInfo(QString pCurrentText);
    void ShowAudioSourceInfo(QString pCurrentText);
    void ShowAudioSinkInfo(QString pCurrentText);

    void ShowFineTuningAudioSilenceSuppresion();

    void ShowSuggestionsForStunServer();
    void GotAnswerForStunServerListRequest(QNetworkReply *pReply);

    void ShowSuggestionsForSipServer();
    void GotAnswerForSipServerListRequest(QNetworkReply *pReply);

    void CreateAccountAtSipServer();

    void SelectNotifySoundFileForStart();
    void SelectNotifySoundFileForStop();
    void SelectNotifySoundFileForIm();
    void SelectNotifySoundFileForCall();
    void SelectNotifySoundFileForCallAcknowledge();
    void SelectNotifySoundFileForCallDeny();
    void SelectNotifySoundFileForCallHangup();
    void SelectNotifySoundFileForError();
    void SelectNotifySoundFileForRegistrationFailed();
    void SelectNotifySoundFileForRegistrationSuccessful();

    void SelectAllSound();
    void DeselectAllSound();
    void SelectAllSystray();
    void DeselectAllSystray();

    void PlayNotifySoundFileForStart();
    void PlayNotifySoundFileForStop();
    void PlayNotifySoundFileForIm();
    void PlayNotifySoundFileForCall();
    void PlayNotifySoundFileForCallAcknowledge();
    void PlayNotifySoundFileForCallDeny();
    void PlayNotifySoundFileForCallHangup();
    void PlayNotifySoundFileForError();
    void PlayNotifySoundFileForRegistrationFailed();
    void PlayNotifySoundFileForRegistrationSuccessful();

    void ClickedButton(QAbstractButton *pButton);
    void ToggleSipServerPasswordVisibility();

private:
    QString SelectSoundFile(QString pEventName, QString pSuggestion);
    void PlayNotifySoundFile(QString pFile);

    int VideoString2ResolutionIndex(std::string pString);

    void LetUserSelectStunServerFromSuggestions();
    void LetUserSelectSipServerFromSuggestions();

    void initializeGUI();
    void LoadConfiguration();
    void SaveConfiguration();

    std::list<std::string>  mLocalAdresses;

    VideoWorkerThread       *mVideoWorker;
    AudioWorkerThread       *mAudioWorker;

    QNetworkAccessManager   *mHttpGetStunServerList;
    static QStringList      mStunServerList;

    QNetworkAccessManager   *mHttpGetSipServerList;
    static QStringList      mSipServerList;

    VideoDevices        mVideoCaptureDevices;
    AudioDevices        mAudioCaptureDevices;
    Homer::Multimedia::AudioDevices mAudioPlaybackDevices;
};

///////////////////////////////////////////////////////////////////////////////

}}

#endif
