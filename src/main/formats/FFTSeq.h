#pragma once
#include "VGMSeq.h"
#include "SeqTrack.h"
#include "Format.h"			//Replace with MP2k-specific format header when that's ready

static const unsigned char delta_time_table[] = { 0, 192, 144, 96, 72, 64, 48, 36, 32, 24, 18, 16, 12, 9, 8, 6, 4, 3, 2};
				//	これ・・・無駄じゃね？
				//                         0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02,
				//						   0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02,
				//					       0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02,
				//						   0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02,
				//						   0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02,
				//						   0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02,
				//						   0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02,
				//						   0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02,
				//						   0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02,
				//						   0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02,
				//						   0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02 };

class FFTSeq
	: public VGMSeq
{
public:
	FFTSeq(RawFile* file, uint32_t offset);
	virtual ~FFTSeq(void);

	virtual bool GetHeaderInfo(void);
	virtual bool GetTrackPointers(void);	//Function to find all of the track pointers.   Returns number of total tracks.
	virtual uint32_t GetID() {return assocWdsID;}

	//virtual int ApplyTable(void);		//create and apply table handler object for sequence
	//void OnSaveAsMidi(void);

protected:
	uint16_t seqID;
	uint16_t assocWdsID;
};


class FFTTrack
	: public SeqTrack
{
public:
	FFTTrack(FFTSeq* parentFile, long offset = 0, long length = 0);
	virtual void ResetVars();
	virtual bool ReadEvent(void);

public:
	bool bNoteOn;
	uint32_t infiniteLoopPt;
	uint8_t infiniteLoopOctave;
	uint32_t loopID[5];
	int loop_counter[5];
	int loop_repeats[5];
	int loop_layer;
	uint32_t loop_begin_loc[5];
	uint32_t loop_end_loc[5];
	uint8_t loop_octave[5];		//1,Sep.2009 revise 
	uint8_t loop_end_octave[5];	//1,Sep.2009 revise
};

/*
class FFTSeqTableHandler : public SeqTableHandler
{
public:
	FFTSeqTableHandler(void);

	virtual void SetNames(void);
	//virtual bool Apply(VGMFile *pVGMFile, uint32_t CRC32);
};
*/