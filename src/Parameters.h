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


	int N_racetrack;		/* Number of tracks */
	int dataWidth;			/* Number of bits per data, Uint: bit */
	int dataWidthSegment;	/* Number of bits per data segment, Uint: bit */
	std::string writeMode;		/* Write mode */
	int NDR;				/* Number of Data per racetrack */

	int N_DataSegment;		/* Number of data segments per data: dataWidth / dataWidthSegment */
	int N_dataSegmentR;		/* Number of data segment per racetrack: NDR * N_DataSegment */

	int dataSegmentLength;  /* dataSegmentLength: n (m-out-of-n), dataWidthSegment + 1 (flip-N-write) or dataWidthSegment (the others) */

	int N_onesDataSegment;	/* Number of bits are one per DataSegment: m */
							/* m-out-of-n code:  {m,n| Min(n), Min(m), C(n,m) > 2 ^ dataWidthSegment } */

	int racetrackLength;	/* NDR * N_DataSegment * dataSegmentLength + NSDR */
	int NPR;				/* Number of Port per racetrack: */
	int NSDR;				/* Number of spare domain per racetrack */


};

#endif // !PARAMETERS_H
