
#include "VCDValue.hpp"


/*!
*/
VCDValue::VCDValue    (
    VCDBit  value
){
    this -> type = VCD_SCALAR;
    this -> value.val_bit = value;
}

/*!
*/
VCDValue::VCDValue    (
    VCDBitVector *  value
){
    this -> type = VCD_VECTOR;
    this -> value.val_vector= value;
}

/*!
*/
VCDValue::VCDValue    (
    VCDReal value
){
    this -> type = VCD_REAL;
    this -> value.val_real = value;
}


VCDValueType   VCDValue::get_type() const{
    return this -> type;
}


/*!
*/
VCDBit       VCDValue::get_value_bit() const{
    return this -> value.val_bit;
}


/*!
*/
VCDBitVector * VCDValue::get_value_vector(){
    return this -> value.val_vector;
}

/*!
*/
const VCDBitVector * VCDValue::get_value_vector() const{
    return this -> value.val_vector;
}


/*!
*/
VCDReal      VCDValue::get_value_real() const{
    return this -> value.val_real;
}

