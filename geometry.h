
#ifndef _GEOMETRY_H__
#define _GEOMETRY_H__

#include<cmath>

template <class t> class Vec2 
{
public:
		union {
			struct { t u, v; };
			struct { t x, y; };
			t raw[2];
		};
	
		Vec2() :u(0), v(0) {};
		Vec2(t _u, t _v) :u(_u), v(_v) {};//����
		Vec2(const Vec2& temp) :u(temp.u), v(temp.v) {};//��������
		//�ع�Vec2��Ҫ�Ĳ���
		//�ڶ���const��������Ӱ����øú����Ķ���ĳ�Ա����
		inline Vec2<t> operator + (const Vec2<t>& temp)const { return Vec2<t>(u + temp.u, v + temp.v); };
		inline Vec2<t> operator - (const Vec2<t>& temp)const { return Vec2<t>(u - temp.u, v - temp.v); };
		inline Vec2<t> operator * (const float& m) const { return Vec2<t>(u * m, v * m); };
		inline t operator * (const Vec2<t>& temp) const { return (x*temp.y-y*temp.x); };
};

template <class t> class Vec3
{
public://����������Ҫpublic������
	union {
		struct { t x, y, z; };
		struct { t ivert, iuv, inorm; };
		t raw[3];
	};

	Vec3() :x(0), y(0) , z(0) {};
	Vec3(t _x, t _y, t _z) :x(_x), y(_y), z(_z) {};//����
	Vec3(const Vec3& temp) :x(temp.x), y(temp.y),z(temp.z) {};//��������
	//�ع�Vec3��Ҫ�Ĳ���
	//�ڶ���const��������Ӱ����øú����Ķ���ĳ�Ա����
	inline Vec3<t> operator + (const Vec3<t>& temp)const { return Vec3<t>(x + temp.x, y + temp.y, z + temp.z);};
	inline Vec3<t> operator - (const Vec3<t>& temp)const { return Vec3<t>(x - temp.x, y - temp.y, z - temp.z);};
	inline Vec3<t> operator * (const float& m) const { return Vec3<t>(x * m, y * m, z * m); };
	//���
	inline Vec3<t> operator ^ (const Vec3<t>& temp)const { return Vec3<t>(y*temp.z-z*temp.y,z*temp.x-x*temp.z,x*temp.y-y*temp.x); };
	//���
	inline t operator* (const Vec3<t>& temp) const { return x*temp.x+y*temp.y+temp.z*z; };
	//���������float �����int��ôĤ����û������
	inline float len() const { return std::sqrt(x * x + y * y + z * z); };
	inline Vec3<t> normalize() const{ float temp = this->len(); return Vec3<t>(x / temp,y / temp, z / temp); };//��һ��
};
//ģ�嶨�� �����������
typedef Vec2<float> Vec2f;
typedef Vec2<int> Vec2i;
typedef Vec3<float> Vec3f;
typedef Vec3<int> Vec3i;


#endif // !_GEOMETRY_H__
