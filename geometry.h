
#ifndef _GEOMETRY_H__
#define _GEOMETRY_H__

#include<cmath>

template <class t> class Vec2 
{
	private:
		t u, v;
		Vec2() :u(0), v(0) {};
		Vec2(t _u, t_v) :u(_u), v(_v) {};//����
		Vec2(const Vec2& temp) :u(temp.u), v(temp.v) {};//��������
		//�ع�Vec2��Ҫ�Ĳ���
		//�ڶ���const��������Ӱ����øú����Ķ���ĳ�Ա����
		inline Vec2<t> operator + (const Vec2<t>& temp)const { return Vec2<t>(u + temp.u, v + temp.v); };
		inline Vec2<t> operator - (const Vec2<t>& temp)const { return Vec2<t>(u - temp.u, v - temp.v); };
		inline Vec2<t> operator * (const float& m) const { return Vec2<t>(u * m, v * m); };
};

template <class t> class Vec3
{
private:
	t x,y,z;
	Vec3() :x(0), y(0) , z(0) {};
	Vec3(t _x, t_y, t_z) :x(_x), y(_y), z(_z) {};//����
	Vec3(const Vec3& temp) :x(temp.x), y(temp.y),z(temp.z) {};//��������
	//�ع�Vec3��Ҫ�Ĳ���
	//�ڶ���const��������Ӱ����øú����Ķ���ĳ�Ա����
	inline Vec3<t> operator + (const Vec3<t>& temp)const
	inline Vec3<t> operator + (const Vec3<t>& temp)const { return Vec2<t>(u + temp.u, v + temp.v); };
	inline Vec3<t> operator - (const Vec3<t>& temp)const { return Vec2<t>(u - temp.u, v - temp.v); };
	inline Vec3<t> operator * (const float& m) const { return Vec2<t>(u * m, v * m); };
	inline Vec3<t> operator * (const Vec3<t>& temp) const { return Vec2<t>(u * m, v * m); };



};



#endif // !_GEOMETRY_H__
