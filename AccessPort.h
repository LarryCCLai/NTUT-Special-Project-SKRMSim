#ifndef ACCESSPORT_H
#define ACCESSPORT_H

class AccessPort {
private:
protected:
	int align;
public:
	AccessPort();
	AccessPort(int _align);
	void setAlign(int num);
	int getAlign();
};

#endif // !ACCESSPORT_H
