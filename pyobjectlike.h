#ifndef PYOBJECTLIKE_H
#define PYOBJECTLIKE_H

#include <array>
#include <cmath>
#include <cstdint>
#include <deque>
#include <forward_list>
#include <iosfwd>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

// Helper to make static_assert always fail for unsupported types

class PyObjectLike
{

  public:
    std::variant<bool, int64_t, uint64_t, double_t, std::string> data;

    // Constructors for different types
    PyObjectLike(int8_t value) : data(static_cast<int64_t>(value))
    {
    }
    PyObjectLike(uint8_t value) : data(static_cast<uint64_t>(value))
    {
    }
    PyObjectLike(int16_t value) : data(static_cast<int64_t>(value))
    {
    }
    PyObjectLike(uint16_t value) : data(static_cast<uint64_t>(value))
    {
    }
    PyObjectLike(int32_t value) : data(static_cast<int64_t>(value))
    {
    }
    PyObjectLike(uint32_t value) : data(static_cast<uint64_t>(value))
    {
    }
    PyObjectLike(int64_t value) : data(value)
    {
    }
    PyObjectLike(uint64_t value) : data(value)
    {
    }
    PyObjectLike(float_t value) : data(static_cast<double_t>(value))
    {
    }
    PyObjectLike(double_t value) : data(value)
    {
    }
    PyObjectLike(const std::string_view value) : data(std::string{value.begin(), value.end()})
    {
    }
    explicit PyObjectLike(std::string &&value) : data(value)
    {
    }
    PyObjectLike(const std::string &value) : data(value)
    {
    }
    PyObjectLike(const char *value) : data(std::string{value})
    {
    }
    PyObjectLike(bool value) : data(value)
    {
    }
    operator std::string()
    {
        if (std::holds_alternative<std::string>(data))
        {
            return std::get<std::string>(data);
        }
        else if (std::holds_alternative<int64_t>(data))
        {
            return std::to_string(std::get<int64_t>(data));
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            return std::to_string(std::get<uint64_t>(data));
        }
        else if (std::holds_alternative<double_t>(data))
        {
            return std::to_string(std::get<double_t>(data));
        }
        else if (std::holds_alternative<bool>(data))
        {
            if (!(std::get<bool>(data)))
            {
                return "False";
            }
            return "True";
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }
    operator bool()
    {
        if (std::holds_alternative<bool>(data))
        {
            return std::get<bool>(data);
        }
        else if (std::holds_alternative<int64_t>(data))
        {
            return std::get<int64_t>(data);
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            return std::get<uint64_t>(data);
        }
        else if (std::holds_alternative<double_t>(data))
        {
            return std::get<double_t>(data);
        }
        else if (std::holds_alternative<std::string>(data))
        {
            auto tmpvar{std::get<std::string>(data)};
            return !(tmpvar.empty());
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }
    operator int8_t()
    {
        if (std::holds_alternative<int64_t>(data))
        {
            return static_cast<int8_t>(std::get<int64_t>(data));
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            return static_cast<int8_t>(std::get<uint64_t>(data));
        }
        else if (std::holds_alternative<double_t>(data))
        {
            return static_cast<int8_t>(std::get<double_t>(data));
        }
        else if (std::holds_alternative<bool>(data))
        {
            if (!(std::get<bool>(data)))
            {
                return 0;
            }
            return 1;
        }
        if (std::holds_alternative<std::string>(data))
        {
            return static_cast<int8_t>(std::stoi(std::get<std::string>(data)));
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }

    operator int16_t()
    {
        if (std::holds_alternative<int64_t>(data))
        {
            return static_cast<int16_t>(std::get<int64_t>(data));
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            return static_cast<int16_t>(std::get<uint64_t>(data));
        }
        else if (std::holds_alternative<double_t>(data))
        {
            return static_cast<int16_t>(std::get<double_t>(data));
        }
        else if (std::holds_alternative<bool>(data))
        {
            if (!(std::get<bool>(data)))
            {
                return 0;
            }
            return 1;
        }
        if (std::holds_alternative<std::string>(data))
        {
            return static_cast<int16_t>(std::stoi(std::get<std::string>(data)));
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }
    operator int32_t()
    {
        if (std::holds_alternative<int64_t>(data))
        {
            return static_cast<int32_t>(std::get<int64_t>(data));
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            return static_cast<int32_t>(std::get<uint64_t>(data));
        }
        else if (std::holds_alternative<double_t>(data))
        {
            return static_cast<int32_t>(std::get<double_t>(data));
        }
        else if (std::holds_alternative<bool>(data))
        {
            if (!(std::get<bool>(data)))
            {
                return 0;
            }
            return 1;
        }
        if (std::holds_alternative<std::string>(data))
        {
            return std::stoi(std::get<std::string>(data));
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }
    operator int64_t()
    {
        if (std::holds_alternative<int64_t>(data))
        {
            return static_cast<int64_t>(std::get<int64_t>(data));
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            return static_cast<int64_t>(std::get<uint64_t>(data));
        }
        else if (std::holds_alternative<double_t>(data))
        {
            return static_cast<int64_t>(std::get<double_t>(data));
        }
        else if (std::holds_alternative<bool>(data))
        {
            if (!(std::get<bool>(data)))
            {
                return 0;
            }
            return 1;
        }
        if (std::holds_alternative<std::string>(data))
        {
            return std::stoll(std::get<std::string>(data));
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }
    operator uint8_t()
    {
        if (std::holds_alternative<int64_t>(data))
        {
            return static_cast<uint8_t>(std::get<int64_t>(data));
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            return static_cast<uint8_t>(std::get<uint64_t>(data));
        }
        else if (std::holds_alternative<double_t>(data))
        {
            return static_cast<uint8_t>(std::get<double_t>(data));
        }
        else if (std::holds_alternative<bool>(data))
        {
            if (!(std::get<bool>(data)))
            {
                return 0;
            }
            return 1;
        }
        if (std::holds_alternative<std::string>(data))
        {
            return static_cast<uint8_t>(std::stoul(std::get<std::string>(data)));
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }
    operator uint16_t()
    {
        if (std::holds_alternative<int64_t>(data))
        {
            return static_cast<uint16_t>(std::get<int64_t>(data));
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            return static_cast<uint16_t>(std::get<uint64_t>(data));
        }
        else if (std::holds_alternative<double_t>(data))
        {
            return static_cast<uint16_t>(std::get<double_t>(data));
        }
        else if (std::holds_alternative<bool>(data))
        {
            if (!(std::get<bool>(data)))
            {
                return 0;
            }
            return 1;
        }
        if (std::holds_alternative<std::string>(data))
        {
            return static_cast<uint16_t>(std::stoul(std::get<std::string>(data)));
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }
    operator uint32_t()
    {
        if (std::holds_alternative<int64_t>(data))
        {
            return static_cast<uint32_t>(std::get<int64_t>(data));
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            return static_cast<uint32_t>(std::get<uint64_t>(data));
        }
        else if (std::holds_alternative<double_t>(data))
        {
            return static_cast<uint32_t>(std::get<double_t>(data));
        }
        else if (std::holds_alternative<bool>(data))
        {
            if (!(std::get<bool>(data)))
            {
                return 0;
            }
            return 1;
        }
        if (std::holds_alternative<std::string>(data))
        {
            return std::stoul(std::get<std::string>(data));
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }
    operator uint64_t()
    {
        if (std::holds_alternative<int64_t>(data))
        {
            return static_cast<uint64_t>(std::get<int64_t>(data));
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            return static_cast<uint64_t>(std::get<uint64_t>(data));
        }
        else if (std::holds_alternative<double_t>(data))
        {
            return static_cast<uint64_t>(std::get<double_t>(data));
        }
        else if (std::holds_alternative<bool>(data))
        {
            if (!(std::get<bool>(data)))
            {
                return 0;
            }
            return 1;
        }
        if (std::holds_alternative<std::string>(data))
        {
            return std::stoull(std::get<std::string>(data));
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }

    operator double_t()
    {
        if (std::holds_alternative<int64_t>(data))
        {
            return static_cast<double_t>(std::get<int64_t>(data));
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            return static_cast<double_t>(std::get<uint64_t>(data));
        }
        else if (std::holds_alternative<double_t>(data))
        {
            return static_cast<double_t>(std::get<double_t>(data));
        }
        else if (std::holds_alternative<bool>(data))
        {
            if (!(std::get<bool>(data)))
            {
                return 0;
            }
            return 1;
        }
        else if (std::holds_alternative<std::string>(data))
        {
            return std::stod(std::get<std::string>(data));
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }
    operator float()
    {
        return static_cast<float>(this->operator double_t());
    }

    bool operator==(const PyObjectLike &other) const
    {
        return data == other.data;
    };
    bool operator!=(const PyObjectLike &other) const
    {
        return data != other.data;
    }
    bool operator>(const PyObjectLike &other) const
    {
        return data > other.data;
    }
    bool operator>=(const PyObjectLike &other) const
    {
        return data >= other.data;
    }
    bool operator<(const PyObjectLike &other) const
    {
        return data < other.data;
    }
    bool operator<=(const PyObjectLike &other) const
    {
        return data <= other.data;
    }
    PyObjectLike operator+(PyObjectLike &&other)
    {
        if (std::holds_alternative<int64_t>(data) && std::holds_alternative<int64_t>(other.data))
        {
            return PyObjectLike(std::get<int64_t>(data) + std::get<int64_t>(other.data));
        }
        else if (std::holds_alternative<uint64_t>(data) && std::holds_alternative<uint64_t>(other.data))
        {
            return PyObjectLike(std::get<uint64_t>(data) + std::get<uint64_t>(other.data));
        }
        else if (std::holds_alternative<double_t>(data) && std::holds_alternative<double_t>(other.data))
        {
            return PyObjectLike(std::get<double_t>(data) + std::get<double_t>(other.data));
        }
        else if (std::holds_alternative<std::string>(data) && std::holds_alternative<std::string>(other.data))
        {
            return PyObjectLike(std::get<std::string>(data) + std::get<std::string>(other.data));
        }
        else if (std::holds_alternative<bool>(data) && std::holds_alternative<bool>(other.data))
        {
            return PyObjectLike(std::get<bool>(data) + std::get<bool>(other.data));
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }

    PyObjectLike operator+(const char *other)
    {
        return PyObjectLike{std::string(*this) + other};
    }
    PyObjectLike operator+(std::string &&other)
    {
        return PyObjectLike{std::string(*this) + other};
    }
    PyObjectLike operator+(const std::string_view other)
    {
        return PyObjectLike{std::string(*this) + std::string(other)};
    }
    PyObjectLike &operator+=(const char *other)
    {
        PyObjectLike tmpobj{std::string(*this) + other};
        data = std::move(tmpobj.data);
        return *this;
    }
    PyObjectLike &operator+=(std::string &&other)
    {
        PyObjectLike tmpobj{std::string(*this) + other};
        data = std::move(tmpobj.data);
        return *this;
    }
    PyObjectLike &operator+=(const std::string_view other)
    {
        PyObjectLike tmpobj{std::string(*this) + std::string(other)};
        data = std::move(tmpobj.data);
        return *this;
    }

    PyObjectLike operator+(char other)
    {
        std::string tmpstring;
        tmpstring += other;
        return PyObjectLike{std::string(*this) + tmpstring};
    }

    PyObjectLike operator+(int8_t &&other)
    {
        return PyObjectLike{int8_t(*this) + other};
    }
    PyObjectLike operator-(int8_t &&other)
    {
        return PyObjectLike{int8_t(*this) - other};
    }
    PyObjectLike operator*(int8_t &&other)
    {
        return PyObjectLike{int8_t(*this) * other};
    }
    PyObjectLike operator/(int8_t &&other)
    {
        return PyObjectLike{int8_t(*this) / other};
    }
    PyObjectLike &operator+=(int8_t &&other)
    {
        data = int8_t(*this) + other;
        return *this;
    }
    PyObjectLike &operator-=(int8_t &&other)
    {
        data = int8_t(*this) - other;
        return *this;
    }
    PyObjectLike &operator*=(int8_t &&other)
    {
        data = int8_t(*this) * other;
        return *this;
    }
    PyObjectLike &operator/=(int8_t &&other)
    {
        data = int8_t(*this) / other;
        return *this;
    }
    PyObjectLike operator+(uint8_t &&other)
    {
        return PyObjectLike{uint8_t(*this) + other};
    }
    PyObjectLike operator-(uint8_t &&other)
    {
        return PyObjectLike{uint8_t(*this) - other};
    }
    PyObjectLike operator*(uint8_t &&other)
    {
        return PyObjectLike{uint8_t(*this) * other};
    }
    PyObjectLike operator/(uint8_t &&other)
    {
        return PyObjectLike{uint8_t(*this) / other};
    }
    PyObjectLike &operator+=(uint8_t &&other)
    {
        data = uint8_t(*this) + other;
        return *this;
    }
    PyObjectLike &operator-=(uint8_t &&other)
    {
        data = uint8_t(*this) - other;
        return *this;
    }
    PyObjectLike &operator*=(uint8_t &&other)
    {
        data = uint8_t(*this) * other;
        return *this;
    }
    PyObjectLike &operator/=(uint8_t &&other)
    {
        data = uint8_t(*this) / other;
        return *this;
    }
    PyObjectLike operator+(int16_t &&other)
    {
        return PyObjectLike{int16_t(*this) + other};
    }
    PyObjectLike operator-(int16_t &&other)
    {
        return PyObjectLike{int16_t(*this) - other};
    }
    PyObjectLike operator*(int16_t &&other)
    {
        return PyObjectLike{int16_t(*this) * other};
    }
    PyObjectLike operator/(int16_t &&other)
    {
        return PyObjectLike{int16_t(*this) / other};
    }
    PyObjectLike &operator+=(int16_t &&other)
    {
        data = int16_t(*this) + other;
        return *this;
    }
    PyObjectLike &operator-=(int16_t &&other)
    {
        data = int16_t(*this) - other;
        return *this;
    }
    PyObjectLike &operator*=(int16_t &&other)
    {
        data = int16_t(*this) * other;
        return *this;
    }
    PyObjectLike &operator/=(int16_t &&other)
    {
        data = int16_t(*this) / other;
        return *this;
    }
    PyObjectLike operator+(uint16_t &&other)
    {
        return PyObjectLike{uint16_t(*this) + other};
    }
    PyObjectLike operator-(uint16_t &&other)
    {
        return PyObjectLike{uint16_t(*this) - other};
    }
    PyObjectLike operator*(uint16_t &&other)
    {
        return PyObjectLike{uint16_t(*this) * other};
    }
    PyObjectLike operator/(uint16_t &&other)
    {
        return PyObjectLike{uint16_t(*this) / other};
    }
    PyObjectLike &operator+=(uint16_t &&other)
    {
        data = uint16_t(*this) + other;
        return *this;
    }
    PyObjectLike &operator-=(uint16_t &&other)
    {
        data = uint16_t(*this) - other;
        return *this;
    }
    PyObjectLike &operator*=(uint16_t &&other)
    {
        data = uint16_t(*this) * other;
        return *this;
    }
    PyObjectLike &operator/=(uint16_t &&other)
    {
        data = uint16_t(*this) / other;
        return *this;
    }
    PyObjectLike operator+(int32_t &&other)
    {
        return PyObjectLike{int32_t(*this) + other};
    }
    PyObjectLike operator-(int32_t &&other)
    {
        return PyObjectLike{int32_t(*this) - other};
    }
    PyObjectLike operator*(int32_t &&other)
    {
        return PyObjectLike{int32_t(*this) * other};
    }
    PyObjectLike operator/(int32_t &&other)
    {
        return PyObjectLike{int32_t(*this) / other};
    }
    PyObjectLike &operator+=(int32_t &&other)
    {
        data = int32_t(*this) + other;
        return *this;
    }
    PyObjectLike &operator-=(int32_t &&other)
    {
        data = int32_t(*this) - other;
        return *this;
    }
    PyObjectLike &operator*=(int32_t &&other)
    {
        data = int32_t(*this) * other;
        return *this;
    }
    PyObjectLike &operator/=(int32_t &&other)
    {
        data = int32_t(*this) / other;
        return *this;
    }
    PyObjectLike operator+(uint32_t &&other)
    {
        return PyObjectLike{uint32_t(*this) + other};
    }
    PyObjectLike operator-(uint32_t &&other)
    {
        return PyObjectLike{uint32_t(*this) - other};
    }
    PyObjectLike operator*(uint32_t &&other)
    {
        return PyObjectLike{uint32_t(*this) * other};
    }
    PyObjectLike operator/(uint32_t &&other)
    {
        return PyObjectLike{uint32_t(*this) / other};
    }
    PyObjectLike &operator+=(uint32_t &&other)
    {
        data = static_cast<uint64_t>(uint32_t(*this) + other);
        return *this;
    }
    PyObjectLike &operator-=(uint32_t &&other)
    {
        data = static_cast<uint64_t>(uint32_t(*this) - other);
        return *this;
    }
    PyObjectLike &operator*=(uint32_t &&other)
    {
        data = static_cast<uint64_t>(uint32_t(*this) / other);
        return *this;
    }
    PyObjectLike &operator/=(uint32_t &&other)
    {
        data = static_cast<uint64_t>(uint32_t(*this) / other);
        return *this;
    }
    PyObjectLike operator+(int64_t &&other)
    {
        return PyObjectLike{int64_t(*this) + other};
    }
    PyObjectLike operator-(int64_t &&other)
    {
        return PyObjectLike{int64_t(*this) - other};
    }
    PyObjectLike operator*(int64_t &&other)
    {
        return PyObjectLike{int64_t(*this) * other};
    }
    PyObjectLike operator/(int64_t &&other)
    {
        return PyObjectLike{int64_t(*this) / other};
    }
    PyObjectLike &operator+=(int64_t &&other)
    {
        data = int64_t(*this) + other;
        return *this;
    }
    PyObjectLike &operator-=(int64_t &&other)
    {
        data = int64_t(*this) - other;
        return *this;
    }
    PyObjectLike &operator*=(int64_t &&other)
    {
        data = int64_t(*this) * other;
        return *this;
    }
    PyObjectLike &operator/=(int64_t &&other)
    {
        data = int64_t(*this) / other;
        return *this;
    }
    PyObjectLike operator+(uint64_t &&other)
    {
        return PyObjectLike{uint64_t(*this) + other};
    }
    PyObjectLike operator-(uint64_t &&other)
    {
        return PyObjectLike{uint64_t(*this) - other};
    }
    PyObjectLike operator*(uint64_t &&other)
    {
        return PyObjectLike{uint64_t(*this) * other};
    }
    PyObjectLike operator/(uint64_t &&other)
    {
        return PyObjectLike{uint64_t(*this) / other};
    }
    PyObjectLike &operator+=(uint64_t &&other)
    {
        data = uint64_t(*this) + other;
        return *this;
    }
    PyObjectLike &operator-=(uint64_t &&other)
    {
        data = uint64_t(*this) - other;
        return *this;
    }
    PyObjectLike &operator*=(uint64_t &&other)
    {
        data = uint64_t(*this) * other;
        return *this;
    }
    PyObjectLike &operator/=(uint64_t &&other)
    {
        data = uint64_t(*this) / other;
        return *this;
    }
    PyObjectLike operator+(float_t &&other)
    {
        return PyObjectLike{float_t(*this) + other};
    }
    PyObjectLike operator-(float_t &&other)
    {
        return PyObjectLike{float_t(*this) - other};
    }
    PyObjectLike operator*(float_t &&other)
    {
        return PyObjectLike{float_t(*this) * other};
    }
    PyObjectLike operator/(float_t &&other)
    {
        return PyObjectLike{float_t(*this) / other};
    }
    PyObjectLike &operator+=(float_t &&other)
    {
        data = float_t(*this) + other;
        return *this;
    }
    PyObjectLike &operator-=(float_t &&other)
    {
        data = float_t(*this) - other;
        return *this;
    }
    PyObjectLike &operator*=(float_t &&other)
    {
        data = float_t(*this) * other;
        return *this;
    }
    PyObjectLike &operator/=(float_t &&other)
    {
        data = float_t(*this) / other;
        return *this;
    }
    PyObjectLike operator+(bool &&other)
    {
        return PyObjectLike{bool(*this) + other};
    }
    PyObjectLike operator-(bool &&other)
    {
        return PyObjectLike{bool(*this) - other};
    }
    PyObjectLike operator*(bool &&other)
    {
        return PyObjectLike{bool(*this) * other};
    }
    PyObjectLike operator/(bool &&other)
    {
        return PyObjectLike{bool(*this) / other};
    }
    PyObjectLike &operator+=(bool &&other)
    {
        data = bool(*this) + other;
        return *this;
    }
    PyObjectLike &operator-=(bool &&other)
    {
        data = bool(*this) - other;
        return *this;
    }
    PyObjectLike &operator*=(bool &&other)
    {
        data = bool(*this) * other;
        return *this;
    }
    PyObjectLike &operator/=(bool &&other)
    {
        data = bool(*this) / other;
        return *this;
    }
    PyObjectLike operator+(double_t &&other)
    {
        return PyObjectLike{double_t(*this) + other};
    }
    PyObjectLike operator-(double_t &&other)
    {
        return PyObjectLike{double_t(*this) - other};
    }
    PyObjectLike operator*(double_t &&other)
    {
        return PyObjectLike{double_t(*this) * other};
    }
    PyObjectLike operator/(double_t &&other)
    {
        return PyObjectLike{double_t(*this) / other};
    }
    PyObjectLike &operator+=(double_t &&other)
    {
        data = double_t(*this) + other;
        return *this;
    }
    PyObjectLike &operator-=(double_t &&other)
    {
        data = double_t(*this) - other;
        return *this;
    }
    PyObjectLike &operator*=(double_t &&other)
    {
        data = double_t(*this) * other;
        return *this;
    }
    PyObjectLike &operator/=(double_t &&other)
    {
        data = double_t(*this) / other;
        return *this;
    }
    PyObjectLike operator++(int)
    {
        if (std::holds_alternative<int64_t>(data))
        {

            int64_t i{std::get<int64_t>(data)};
            data = i + 1;
            return PyObjectLike(i);
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            uint64_t i{std::get<uint64_t>(data)};
            data = i + 1;
            return PyObjectLike(i);
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }
    PyObjectLike operator++()
    {
        if (std::holds_alternative<int64_t>(data))
        {

            int64_t i{std::get<int64_t>(data)};
            return PyObjectLike(i + 1);
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            uint64_t i{std::get<uint64_t>(data)};
            return PyObjectLike(i + 1);
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }
    PyObjectLike operator--()
    {
        if (std::holds_alternative<int64_t>(data))
        {

            int64_t i{std::get<int64_t>(data)};
            return PyObjectLike(i - 1);
        }
        else if (std::holds_alternative<uint64_t>(data))
        {
            uint64_t i{std::get<uint64_t>(data)};
            return PyObjectLike(i - 1);
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }
    PyObjectLike operator--(int)
    {
        if (std::holds_alternative<int64_t>(data))
        {

            int64_t i{std::get<int64_t>(data)};
            data = i - 1;
            return PyObjectLike(i);
        }
        if (std::holds_alternative<uint64_t>(data))
        {
            uint64_t i{std::get<uint64_t>(data)};
            data = i - 1;
            return PyObjectLike(i);
        }
        else
        {
            throw std::runtime_error("Unsupported type");
        }
    }
};
template <> struct std::hash<PyObjectLike>
{
    std::size_t operator()(const PyObjectLike &obj) const
    {
        if (std::holds_alternative<int64_t>(obj.data))
        {
            return std::hash<int64_t>{}(std::get<int64_t>(obj.data));
        }
        else if (std::holds_alternative<uint64_t>(obj.data))
        {
            return std::hash<uint64_t>{}(std::get<uint64_t>(obj.data));
        }
        else if (std::holds_alternative<double_t>(obj.data))
        {
            return std::hash<double_t>{}(std::get<double_t>(obj.data));
        }
        else if (std::holds_alternative<bool>(obj.data))
        {
            return std::hash<bool>{}(std::get<bool>(obj.data));
        }
        else if (std::holds_alternative<std::string>(obj.data))
        {
            return std::hash<std::string>{}(std::get<std::string>(obj.data));
        }
        else
        {
            return 0;
        }
    }
};

std::ostream &operator<<(std::ostream &os, const PyObjectLike &ti)
{
    if (std::holds_alternative<int64_t>(ti.data))
    {
        os << std::get<int64_t>(ti.data);
    }
    else if (std::holds_alternative<uint64_t>(ti.data))
    {
        os << std::get<uint64_t>(ti.data);
    }
    else if (std::holds_alternative<double_t>(ti.data))
    {
        os << std::get<double_t>(ti.data);
    }
    else if (std::holds_alternative<bool>(ti.data))
    {
        os << std::get<bool>(ti.data);
    }
    else if (std::holds_alternative<std::string>(ti.data))
    {
        os << std::get<std::string>(ti.data);
    }
    return os;
}

std::ostream &_operator(std::ostream &os, const std::vector<PyObjectLike> &v)
{

    if (v.size() == 0)
    {
        os << "";
        return os;
    }
    auto it{v.begin()};

    while (it != v.end() - 1)
    {
        os << *it;
        os << ", ";

        it++;
    }
    os << *it;

    return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<PyObjectLike> &v)
{
    os << '[';
    _operator(os, v);
    os << ']';
    return os;
}
std::ostream &operator<<(std::ostream &os, const std::deque<PyObjectLike> &v)
{
    os << '[';
    std::vector<PyObjectLike> vec{v.begin(), v.end()};
    _operator(os, vec);
    os << ']';
    return os;
}
std::ostream &operator<<(std::ostream &os, const std::forward_list<PyObjectLike> &v)
{
    os << '[';
    std::vector<PyObjectLike> vec{v.begin(), v.end()};
    _operator(os, vec);
    os << ']';
    return os;
}
std::ostream &operator<<(std::ostream &os, const std::list<PyObjectLike> &v)
{
    os << '[';
    std::vector<PyObjectLike> vec{v.begin(), v.end()};
    _operator(os, vec);
    os << ']';
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::set<PyObjectLike> &v)
{
    os << '{';
    std::vector<PyObjectLike> vec{v.begin(), v.end()};
    _operator(os, vec);
    os << '}';
    return os;
}
std::ostream &operator<<(std::ostream &os, const std::unordered_set<PyObjectLike> &v)
{
    os << '{';
    std::vector<PyObjectLike> vec{v.begin(), v.end()};
    _operator(os, vec);
    os << '}';
    return os;
}
template <size_t N> std::ostream &operator<<(std::ostream &os, const std::array<PyObjectLike, N> &v)
{
    os << '[';
    std::vector<PyObjectLike> vec{v.begin(), v.end()};
    _operator(os, vec);
    os << ']';
    return os;
}

template <typename T> std::ostream &operator<<(std::ostream &os, std::map<PyObjectLike, T> &v)
{
    if (v.size() == 0)
    {
        os << "{}";
        return os;
    }
    auto it{v.begin()};

    os << '{';
    size_t size_of_map{v.size()};
    size_t size_couter{1};
    while (it != v.end())
    {
        size_couter++;
        os << it->first << " : " << it->second << ", ";

        it++;
        if (size_couter == size_of_map)
        {
            break;
        }
    }
    os << it->first << " : " << it->second << '}';
    return os;
}

template <typename T> std::ostream &operator<<(std::ostream &os, std::unordered_map<PyObjectLike, T> &v)
{
    std::map tmpmap{v.begin(), v.end()};
    return os << tmpmap;
}

#endif
