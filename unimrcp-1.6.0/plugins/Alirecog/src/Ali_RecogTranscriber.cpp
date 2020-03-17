#include"Ali_RecogTranscriber.h"



CAliTranscriber::CAliTranscriber() noexcept
{

}

//CAliTranscriber::CAliTranscriber(string		appKey,
//								string		AccessKey,
//								string		Secret,
//								string		Format,
//								string		SampleRate,
//								string		intermediateResult,
//								string		inverseText,
//								string		voiceDetection,
//								string		maxEndSilence,
//								string		maxStartSilence,
//								string		PunctuationPrediction,
//								string		CustomizationId,
//								string		VocabularyId,
//								string		OutputFormat,
//								string		ContextParam) noexcept:
//								m_CallBack(nullptr),
//								m_Request(nullptr),
//								m_Flag(FALSE),
//								CAliResource(appKey, 
//											AccessKey, 
//											Secret, 
//											Format, 
//											SampleRate, 
//											intermediateResult, 
//											inverseText, 
//											voiceDetection, 
//											maxEndSilence,
//											maxStartSilence,
//											PunctuationPrediction, 
//											CustomizationId, 
//											VocabularyId, 
//											OutputFormat, 
//											ContextParam)
//
//{
//		//m_CallBack = new  SpeechTranscriberCallback;
//		//if (m_CallBack) {
//		//	m_CallBack->setOnChannelClosed(CAliResource::OnChannelClosed, this);
//		//	m_CallBack->setOnTaskFailed(CAliResource::OnTaskFailed, this);
//		//	m_CallBack->setOnTranscriptionStarted(CAliResource::OnTranscriptionStarted, this);// ����ʶ�������ص�����
//		//	m_CallBack->setOnTranscriptionResultChanged(CAliResource::OnTranscriptionResultChanged, this);// ����ʶ�����仯�ص�����
//		//	m_CallBack->setOnTranscriptionCompleted(CAliResource::OnTranscriptionCompleted, this);// ��������תд�����ص�����
//		//	m_CallBack->setOnSentenceBegin(CAliResource::OnSentenceBegin,this);// ����һ�仰��ʼ�ص���
//		//	m_CallBack->setOnSentenceEnd(CAliResource::OnSentenceEnd,this);// ����һ�仰�����ص�����
//		//}
//}

CAliTranscriber::~CAliTranscriber() noexcept
{
	if (m_CallBack) {
		delete m_CallBack;
		m_CallBack = nullptr;
	}
}

//inline void  CAliTranscriber::OnTranscriptionStarted(NlsEvent* ev, void* AliRe)
//{
//	CAliTranscriber * re = static_cast<CAliTranscriber *>(AliRe);
//	if (re)
//		re->OnTranscriptionStarted(ev);
//	return;
//}
//
// inline void  CAliTranscriber::OnTranscriptionResultChanged(NlsEvent* ev, void* AliRe)
//{
//	CAliTranscriber * re = static_cast<CAliTranscriber *>(AliRe);
//	if (re)
//		re->OnTranscriptionResultChanged(ev);
//	return;
//}
//
// inline void  CAliTranscriber::OnTranscriptionCompleted(NlsEvent* ev, void* AliRe)
//{
//	CAliTranscriber * re = static_cast<CAliTranscriber *>(AliRe);
//	if (re)
//		re->OnTranscriptionCompleted(ev);
//	return;
//}
//
// inline void  CAliTranscriber::OnSentenceBegin(NlsEvent* ev, void* AliRe)
//{
//	CAliTranscriber * re = static_cast<CAliTranscriber *>(AliRe);
//	if (re)
//		re->OnSentenceBegin(ev);
//	return;
//}
//
// inline void  CAliTranscriber::OnSentenceEnd(NlsEvent* ev, void* AliRe)
//{
//	CAliTranscriber * re = static_cast<CAliTranscriber *>(AliRe);
//	if (re)
//		re->OnSentenceEnd(ev);
//	return;
//}
//
// inline void CAliTranscriber::OnTaskFailed(NlsEvent* ev, void* AliRe)
//{
//	CAliTranscriber * re = static_cast<CAliTranscriber *>(AliRe);
//	if (re)
//		re->OnTaskFailed(ev);
//	return;
//}
//
//inline void CAliTranscriber::OnChannelClosed(NlsEvent* ev, void* AliRe)
//{
//	CAliTranscriber * re = static_cast<CAliTranscriber *>(AliRe);
//	if (re)
//		re->OnChannelClosed(ev);
//	return;
//}


void CAliTranscriber::OnTranscriptionStarted(NlsEvent* ev)
{

}

void CAliTranscriber::OnTranscriptionResultChanged(NlsEvent* ev)
{
	m_result = ev->getResult();
	if (nullptr != m_AliCh) {
		m_AliCh->RecogResultSet(m_result);
	}
}

void CAliTranscriber::OnTranscriptionCompleted(NlsEvent* ev)
{
	m_result = ev->getResult();
	if (nullptr != m_AliCh) {
		m_AliCh->RecogResultSet(m_result);
	}
}

void CAliTranscriber::OnSentenceBegin(NlsEvent* ev)
{

}

void CAliTranscriber::OnSentenceEnd(NlsEvent* ev)
{
	m_result = ev->getResult();
	if (nullptr != m_AliCh) {
		m_AliCh->RecogResultSet(m_result);
	}
}

void CAliTranscriber::OnChannelClosed(NlsEvent* ev)
{

}

void CAliTranscriber::OnTaskFailed(NlsEvent* ev)
{
	//m_Flag = TRUE;
	LOG_INFO("Ali Task start failed Msg :%s", ev->getErrorMessage());
}


bool CAliTranscriber::DoRecogRequestInit(	const string& appKey,
											const string& AccessKey,
											const string& Secret,
											const string& Format,
											const string& SampleRate,
											const string& intermediateResult,
											const string& inverseText,
											const string& voiceDetection,
											const string& maxEndSilence,
											const string& maxStartSilence,
											const string& PunctuationPrediction,
											const string& CustomizationId,
											const string& VocabularyId,
											const string& OutputFormat,
											const string& ContextParam)
{

	m_appkey = appKey;
	m_AccessKey = AccessKey;
	m_Secret = Secret;
	m_Format = Format;
	m_SampleRate = SampleRate;
	m_intermediateResult = intermediateResult;
	m_inverseText = inverseText;
	m_voiceDetection = voiceDetection;
	m_maxEndSilence = maxEndSilence;
	m_maxStartSilence = maxStartSilence;
	m_PunctuationPrediction = PunctuationPrediction;
	m_CustomizationId = CustomizationId;
	m_VocabularyId = VocabularyId;
	m_OutputFormat = OutputFormat;
	m_ContextParam = ContextParam;


	m_CallBack = new  SpeechTranscriberCallback;
	if (m_CallBack) {
		m_CallBack->setOnChannelClosed(CAliResource::OnChannelClosed, this);
		m_CallBack->setOnTaskFailed(CAliResource::OnTaskFailed, this);
		m_CallBack->setOnTranscriptionStarted(CAliResource::OnTranscriptionStarted, this);// ����ʶ�������ص�����
		m_CallBack->setOnTranscriptionResultChanged(CAliResource::OnTranscriptionResultChanged, this);// ����ʶ�����仯�ص�����
		m_CallBack->setOnTranscriptionCompleted(CAliResource::OnTranscriptionCompleted, this);// ��������תд�����ص�����
		m_CallBack->setOnSentenceBegin(CAliResource::OnSentenceBegin, this);// ����һ�仰��ʼ�ص���
		m_CallBack->setOnSentenceEnd(CAliResource::OnSentenceEnd, this);// ����һ�仰�����ص�����
	}

	//bool ret = TRUE;

	//if (m_Request && ret) {
	//	if (!DoCheakRecogToKen()) {
	//		LOG_ERROR("<--- DoCheakRecogToKen falied --->");
	//		ret = FALSE;
	//	}
	//	else {
	//		m_Request->setToken(m_token.c_str());
	//		m_Request->setAppKey(m_appkey.c_str());
	//		m_Request->setFormat(m_Format.c_str());
	//		m_Request->setSampleRate(8000);
	//		m_Request->setIntermediateResult(true);
	//		m_Request->setPunctuationPrediction(true);
	//		m_Request->setInverseTextNormalization(true);
	//		//m_Request->setSampleRate((m_SampleRate == "8000" ? 8000 : 16000));
	//		//m_Request->setIntermediateResult(((m_intermediateResult == "true") ? true : false)); //�����м���
	//		////m_Request->setEnableVoiceDetection(((m_voiceDetection == "true") ? true : false)); //�����������
	//		//m_Request->setPunctuationPrediction(((m_PunctuationPrediction == "true") ? true : false));// �����Ƿ��ں�������ӱ��, ��ѡ����. Ĭ��false
	//		//m_Request->setInverseTextNormalization(((m_inverseText == "true") ? true : false));
	//		//m_Request->setSemanticSentenceDetection(false); // �����Ƿ�����Ͼ�, ��ѡ����. Ĭ��false
	//		m_Request->setMaxSentenceSilence(800);

	//		//if (!m_CustomizationId.empty())
	//		//{
	//		//	m_Request->setCustomizationId(m_CustomizationId.c_str());
	//		//}

	//		//if (!m_VocabularyId.empty())
	//		//{
	//		//	m_Request->setVocabularyId(m_VocabularyId.c_str());
	//		//}


	//		if (m_Request->start() < 0) {
	//			LOG_ERROR("<--- Ali server recog start failed --->");
	//			ret = FALSE;
	//		}
	//	}

	//}

	return TRUE;
}

bool CAliTranscriber::DoCreateRecogRequest()
{
	bool ret = TRUE;

	if ((nullptr != m_CallBack) && (nullptr == m_Request)) {
		m_Request = NlsClient::getInstance()->createTranscriberRequest(m_CallBack);
	}

	if (nullptr == m_Request) {
		m_Request = nullptr;
		ret = FALSE;
	}

	if (m_Request && ret) {
		if (!DoCheakRecogToKen()) {
			LOG_ERROR("<--- DoCheakRecogToKen falied --->");
			ret = FALSE;
		}
		else {
			m_Request->setToken(m_token.c_str());
			m_Request->setAppKey(m_appkey.c_str());
			m_Request->setFormat(m_Format.c_str());
			m_Request->setSampleRate(8000);
			m_Request->setIntermediateResult(true);
			m_Request->setPunctuationPrediction(true);
			m_Request->setInverseTextNormalization(true);
			//m_Request->setSampleRate((m_SampleRate == "8000" ? 8000 : 16000));
			//m_Request->setIntermediateResult(((m_intermediateResult == "true") ? true : false)); //�����м���
			////m_Request->setEnableVoiceDetection(((m_voiceDetection == "true") ? true : false)); //�����������
			//m_Request->setPunctuationPrediction(((m_PunctuationPrediction == "true") ? true : false));// �����Ƿ��ں�������ӱ��, ��ѡ����. Ĭ��false
			//m_Request->setInverseTextNormalization(((m_inverseText == "true") ? true : false));
			//m_Request->setSemanticSentenceDetection(false); // �����Ƿ�����Ͼ�, ��ѡ����. Ĭ��false
			m_Request->setMaxSentenceSilence(800);

			//if (!m_CustomizationId.empty())
			//{
			//	m_Request->setCustomizationId(m_CustomizationId.c_str());
			//}

			//if (!m_VocabularyId.empty())
			//{
			//	m_Request->setVocabularyId(m_VocabularyId.c_str());
			//}
			if (m_Request->start() < 0) {
				LOG_ERROR("<--- Ali server recog start failed --->");
				ret = FALSE;
			}
		}
	}
	return ret;
}

void CAliTranscriber::DoDestroyRecogRequest()
{
	if (m_Request) {
		m_Flag = TRUE;
		if (m_Flag) {
			
			//ֱ�ӶϿ������ȷ��񷵻�
			LOG_INFO("wiat for Ali server disconnect --> cancel")
				m_Request->cancel();
		}
		else {
			LOG_INFO("wiat for Ali server disconnect --> stop")
				m_Request->stop();
		}

		NlsClient::getInstance()->releaseTranscriberRequest(m_Request);
		DoCleanAliPram();
		m_Request = nullptr;
		m_Flag = FALSE;
	}


	LOG_INFO("<==== wiat for Ali server disconnect succee ====>");
}

const char * CAliTranscriber::DoRecogResultGet()const
{
	return nullptr;
}

int	CAliTranscriber::DoWriteFrame(const mpf_frame_t *frame)
{
	if (nullptr == m_Request || nullptr == frame)
		return 0;
	
	return m_Request->sendAudio(static_cast<const char *>(frame->codec_frame.buffer), frame->codec_frame.size);
}

void CAliTranscriber::DoSetChannel(CAliChannel * AliCh)
{
	if (nullptr == AliCh)
		return;
	m_AliCh = AliCh;
	return;
}
