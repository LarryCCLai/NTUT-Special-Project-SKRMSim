#include"AccessPort.h"

AccessPort::AccessPort() {
	align = -1;
}
AccessPort::AccessPort(int _align) {
	align = _align;
}
void AccessPort::setAlign(int num) {
	align = num;
}
int AccessPort::getAlign() {
	return align;
}