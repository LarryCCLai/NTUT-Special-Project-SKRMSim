#ifndef DOMAIN_H
#define DOMAIN_H

class Domain {
private:
	int data; // bit
protected:
public:
	Domain();
	Domain(int d);
	~Domain();
	void setData(int num);
	int getData();
};

#endif // !DOMAIN_H

