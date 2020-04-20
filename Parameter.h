#ifndef PARAMETER_H
#define PARAMETER_H

enum WriteMode {
	General,
	Flip_N_Write,
	DCW,
	Permutation_Write,
	M_out_of_N_Write
};

class Parameter {
public:
	int dataWidth;			/* Number of bits per data, Uint: bit */
	int dataWidthSegment;	/* Number of bits per data segment, Uint: bit */
	WriteMode WMode;		/* Write mode */
	int NDR;				/* Number of Data per racetrack */
	
	int N_DataSegment;		/* Number of data segments per data: dataWidth / dataWidthSegment */
	int N_dataSegmentR;		/* Number of data segment per racetrack: NDR * N_DataSegment */

	int dataSegmentLength;  /* dataSegmentLength: n (m-out-of-n), dataWidthSegment + 1 (flip-N-write) or dataWidthSegment (the others) */

	int N_onesDataSegment;	/* Number of bits are one per DataSegment: m */
							/* m-out-of-n code:  {m,n| Min(n), Min(m), C(n,m) > 2 ^ dataWidthSegment } */
	
	
	int racetrackLength;		/* NDR * N_DataSegment * dataSegmentLength + NSDR */
	int NPR;				/* Number of Port per racetrack: */
	int NSDR;				/* Number of spare domain per racetrack */


	Parameter() {
	}
	~Parameter();
	//void CalculateMOutOfN(int& m, int& n,)
	//ReadParameterFile();
};

#endif // !PARAMETER_H

