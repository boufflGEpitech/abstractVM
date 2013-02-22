#ifndef			__OPERAND_HPP__
#define			__OPERAND_HPP__

#include		<iostream>
#include		<sstream>
#include		<string>
#include		"enum.hh"
#include		"Bios.hh"
#include		"IOperand.hh"

template<class T> 
class	Operand : public IOperand
{
private:
  T	  				_value;
  std::string				  _svalue;
  int					_prec;
  eOperandType				_type;
  Bios					*_bios;

public:
  Operand(const std::string &value, eOperandType t);
  virtual ~Operand();

  /*************/

  std::string const			&toString() const;

  /*************/

  int					getPrecision() const;
  eOperandType				getType() const;

  /*************/

  void					setType(eOperandType type);

  /*************/

  IOperand				*operator+(const IOperand &rhs) const;
  IOperand				*operator-(const IOperand &rhs) const;
  IOperand				*operator*(const IOperand &rhs) const;
  IOperand				*operator/(const IOperand &rhs) const;
  IOperand				*operator%(const IOperand &rhs) const;
  IOperand				*operator=(const IOperand &rhs);
  bool					operator==(const IOperand &rhs) const;
};

template <typename T>
Operand<T>::Operand(const std::string &value, eOperandType t) : _svalue(value), _type(t)
{
  _bios = new Bios();
}

template <typename T>
Operand<T>::~Operand()
{

}

  /*************/

template <typename T>
std::string const			&Operand<T>::toString() const
{
  return (this->_svalue);
}

  /*************/

template <typename T>
int					Operand<T>::getPrecision() const
{
  return (_prec);
}

template <typename T>
eOperandType				Operand<T>::getType() const
{
  return (this->_type);
}

  /*************/

template <typename T>
void					Operand<T>::setType(eOperandType type)
{
  this->_type = type;
}
  /*************/

template <typename T>
IOperand				*Operand<T>::operator+(const IOperand &rhs) const
{ 
  eOperandType				t;
  std::string				resString;  
  std::stringstream			ss1(this->toString()), ss2(rhs.toString()), ss;
  T					res, val1, val2;

  ss1 >> val1;
  ss2 >> val2;
  // std::cout << val2 << std::endl;
  res = val1 + val2;
  ss << res;
  std::cout << ss.str() << std::endl;
  t = this->getType();
  if (this->getType() < rhs.getType())
  t = rhs.getType();
  std::cout << "le type : " << t <<  std::endl;
  // std::string yop = ss.str();
  //std::cout << "juste avant le segfault" << std::endl;
  //IOperand *n = 
  return (this->_bios->createOperand(Int8, ss.str()));
  //std::cout << "xdaiptdr" << std::endl;
  //return(n);
}

  /***************/

template <typename T>
IOperand				*Operand<T>::operator-(const IOperand &rhs) const
{
  eOperandType				t;
  std::string				resString;
  std::stringstream			ss1(this->toString()), ss2(rhs.toString()), ss;
  T					res, val1, val2;

  ss1 >> val1;
  ss2 >> val2;
  res = val1 - val2;
  ss << res;
  t = this->getType();
  if (this->getType() < rhs.getType())
    t = rhs.getType();
  return(this->_bios->createOperand(t, ss.str()));
}

template <typename T>
IOperand				*Operand<T>::operator*(const IOperand &rhs) const
{
  eOperandType				t;
  std::string				resString;
  std::stringstream			ss1(this->toString()), ss2(rhs.toString()), ss;
  T					res, val1, val2;

  ss1 >> val1;
  ss2 >> val2;
  res = val1 * val2;
  ss << res;
  t = this->getType();
  if (this->getType() < rhs.getType())
    t = rhs.getType();
  return(this->_bios->createOperand(t, ss.str()));
}

template <typename T>
IOperand				*Operand<T>::operator/(const IOperand &rhs) const
{
  eOperandType				t;
  std::string				resString;
  std::stringstream			ss1(this->toString()), ss2(rhs.toString()), ss;
  T					res, val1, val2;

  ss1 >> val1;
  ss2 >> val2;
  res = val1 / val2;
  ss << res;
  t = this->getType();
  if (this->getType() < rhs.getType())
    t = rhs.getType();
  return(this->_bios->createOperand(t, ss.str()));
}

template <>
inline IOperand				*Operand<float>::operator%(const IOperand &rhs) const
{
  std::string tmp = rhs.toString();
  return NULL;
}

template <>
inline IOperand				*Operand<double>::operator%(const IOperand &rhs) const
{
  std::string tmp = rhs.toString();
  return NULL;
}

template <typename T>
IOperand				*Operand<T>::operator%(const IOperand &rhs) const
{
  eOperandType				t;
  std::string				resString;
  std::stringstream			ss1(this->toString()), ss2(rhs.toString()), ss;
  T					res, val1, val2;

  ss1 >> val1;
  ss2 >> val2;
  res = val1 % val2;
  ss << res;
  t = this->getType();
  if (this->getType() < rhs.getType())
    t = rhs.getType();
  return(this->_bios->createOperand(t, ss.str()));
}

template <typename T>
IOperand				*Operand<T>::operator=(const IOperand &rhs)
{
  return (this->_bios->createOperand(rhs.getType(), rhs.toString()));
}

template <typename T>
bool					Operand<T>::operator==(const IOperand &rhs) const
{
  if ((this->getType() == rhs.getType()) && (this->toString() == rhs.toString()))
    return (true);
  return (false);
}

#endif
