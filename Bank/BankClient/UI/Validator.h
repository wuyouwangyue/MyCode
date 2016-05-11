#ifndef _VALIDATOR_H_
#define _VALIDATOR_H_

#include <ctype.h>
#include <string>

///У���ļ�

namespace UI
{

///У������
bool ValidateName(const std::string& str, char ch);
///У������
bool ValidatePass(const std::string& str, char ch);
///У������֤
bool ValidateId(const std::string& str, char ch);
///У���½Id
bool ValidateAccountId(const std::string& str, char ch);
///У��Ǯ����ֻ������λС����С��ǰ�������8λ���ܳ��Ȳ�����11λ������С����
bool ValidateMoney(const std::string& str, char ch);
}


#endif //_VALIDATOR_H_