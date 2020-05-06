#ifndef PARAMETERS_H
#define PARAMETERS_H
#include"../config/Config.h"
class Parameters{
private:
	std::map<int, std::pair<int, int>> M_N_Table;
public:
	Parameters();
	~Parameters() {};
	void SetParams(Config* c);
	void CalculateMOutOfN(int&, int&);
	void Print();
	void CreateParamsFile(std::string fileName);
	
	int N_racetrack;		/* 	Number of tracks */
	int dataWidth;			/* 	Number of bits per data */
	int dataWidthSegment;	/* 	Number of bits per data segment */
	WriteMode writeMode;	/* 	Write mode */
	int NDR;				/* 	Number of Data per racetrack */
	bool RealWrite; /*Only Calculate = false or Real Write = true */

	int N_DataSegment;		/* 	Number of data segments per data: dataWidth / dataWidthSegment */
	
	int dataSegmentLength;  /* 	dataSegmentLength:
								m-out-of-n = n;
								FNW, Combine_PW_FNW = dataWidthSegment +1;
								Others = dataWidthSegment
							*/

	int N_onesDataSegment;	/* 	Number of bits are one per DataSegment: 
								m-out-of-n = m
								Others = NULL
							*/

	int racetrackLength;	/* 	NDR * N_DataSegment * dataSegmentLength + NSDR */
	int NPR;				/* 	Number of Port per racetrack: 
								
							*/
	int NSDR;				/* 	Number of spare domain per racetrack */


};

#endif // !PARAMETERS_H
