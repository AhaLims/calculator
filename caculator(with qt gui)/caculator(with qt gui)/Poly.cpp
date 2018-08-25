#include"Poly.h"
#include"source.h"
//#define DEBUG
Poly::Poly(string expression, string v):variable(v),MaxTime(0)
{//必须是不含括号的 可以不按照顺序
#ifdef DEBUG
	if (expression == "test")
	{
		int time;
		std::cout << "input max time\n";
		std::cin >> time;
		set_MaxTime(time);
		for (int i = MaxTime; i >= 0; i--)
			std::cin >> coefficient[i];
	}
#endif // DEBUG
}
Poly::Poly(int time, double * value, string v) :MaxTime(time), variable(v)
{
	coefficient.resize(MaxTime + 1);
	for (int i = MaxTime; i >= 0; i--)
	{
		coefficient[i] = value[i];
	}
}
Poly Poly::get_derivative()
{
	Poly derivative(string(""), variable);
	if (MaxTime == 1)
	{
		double tmp = this->coefficient[1];
		derivative.set_MaxTime(MaxTime - 1);
		derivative.set_coeff(0, tmp);
		return derivative;
	}
	//if (MaxTime == 1)std::cout << "Maxtime == 1\n";
	derivative.set_MaxTime(MaxTime - 1);
	for (int i = 0; i <= MaxTime - 1; i++)
	{
		//if (MaxTime == 1)std::cout << "Maxtime == 1\n";
		//std::cout << this->get_coeff(i + 1) << "\n";
		derivative.set_coeff(i, (i+1) * this->get_coeff(i + 1));
	}
	return derivative;
}
double Poly::get_derivative_value(double x)
{
	return get_derivative().get_ans(x);
}
Poly Poly::get_integral()
{
	Poly integral(string(""), variable);
	integral.set_MaxTime(MaxTime + 1);
	integral.set_coeff(0, 0);
	for (int i = 1; i <= MaxTime + 1; i++)
	{
		integral.set_coeff(i, this->get_coeff(i - 1) / i);
	}
	return integral;
}
string Poly::output()
{
	string expression;
	expression = std::to_string(coefficient[MaxTime]) + variable + "^" + std::to_string(MaxTime);
	if (MaxTime == 0)return expression;
	for (int i = MaxTime - 1; i > 0; i--)
	{
		if (coefficient[i] == 0)
		{
			continue;
		}
		else if (coefficient[i] < 0)
		{
			expression += std::to_string(coefficient[i]) +"*"  + variable + "^" + std::to_string(i);
		}
		else
		expression += "+" + std::to_string(coefficient[i]) + "*" + variable + "^" + std::to_string(i);
	}
	if(coefficient[0] < 0)expression += std::to_string(coefficient[0]);
	else if(coefficient[0] > 0) expression += "+" + std::to_string(coefficient[0]);
	return expression;
}
double Poly::get_ans(double value)
{
	//std::cout << MaxTime << std::endl;
	double answer = coefficient[0];
	if (MaxTime == 0)return answer;
	for (int i = 1; i <= MaxTime; i++)
	{
		answer += coefficient[i] * pow(value, i);
	}
	return answer;
}
void Poly::set_MaxTime(int time)
{
	if (MaxTime < time)coefficient.resize(time + 5);//time + 1
	MaxTime = time;
}
int Poly::get_MaxTime()
{
	return MaxTime;
}
void Poly::set_coeff(int time, double coeff)
{
	if (time > MaxTime)return;
	coefficient[time] = coeff;
}
double Poly::get_coeff(int time)
{
	if (time > MaxTime)return 0;
	return coefficient[time];
}
//[a,b] 
bool Poly::solve(double* ans ,int &amount)
{
	if (MaxTime == 0)return false;
	int ans_amount = get_ans_amount();
	if (ans_amount == 0)return false;
	amount = ans_amount;
	ans = new double[ans_amount];
	Poly tmp = *this;
	/////////////////////////////////////////////////////////
	/*get answer and update tmp*/
	for (int i = 0; i<ans_amount; i++)
	{
		ans[i] = tmp.get_one_ans(MaxTime - i);//right
		double temp,t;
		//除去因子
		t = tmp.get_coeff(MaxTime);
		//tmp.set_coeff(MaxTime, 0);
		//tmp.set_coeff(MaxTime  - 1, tmp.get_coeff(MaxTime));
		for (int j = MaxTime - 1; j >= 0; j--)
		{
			if (j == MaxTime - 1)temp = t;
			else temp = tmp.get_coeff(j + 1) * ans[i] + t;////
			t = tmp.get_coeff(j);
			tmp.set_coeff(j,temp);
		}
		tmp.set_coeff(MaxTime, 0);
		//tmp.set_MaxTime(MaxTime - 1);
	}
#ifdef DEBUG
	std::cout << "ans is\n";
	for (int i = 0; i < ans_amount; i++)
		std::cout << ans[i] << std::endl;
#endif // DEBUG

	return true;
}
double Poly::get_one_ans(int time) 
{
	int B, k;
	bool flag = false;
	/*get the first value and then use newton way to get one answer*/
	//for (int i = get_MaxTime() - 1; i >= 0; i--)
	for (int i = time - 1; i >= 0; i--)
	{
		//if ((get_coeff(i) < 0 && get_coeff(MaxTime) > 0) || (get_coeff(i) > 0 && get_coeff(MaxTime) < 0))
		if ((get_coeff(i) < 0 && get_coeff(time) > 0) || (get_coeff(i) > 0 && get_coeff(time) < 0))
		{
			if (flag == false)
			{
				flag = true;
				k = i;
				B = get_coeff(i);
			}
			else
			{
				if (fabs(B) < fabs(get_coeff(i)))
					B = get_coeff(i);
			}

		}
	}
	double x = 1 + pow(fabs(B / get_coeff(time)), (double)(1)/k);
	return newton(x);
}
int Poly::get_ans_amount()
{
	//看的是负无穷 正无穷 所以只看系数的正负就好了
	int ans_amount = 0;
	Poly der = *this;
	bool now_b, now_a, formal_a, formal_b;
	if (der.get_coeff(MaxTime) < 0)
	{
		formal_a = formal_b = false;
		if (MaxTime % 2 == 0)
			formal_a = !formal_a;
	}
	else
	{
		formal_a = formal_b = true;
		if (MaxTime % 2 == 0)
			formal_a = !formal_a;
	}
	for (int i = 1; i <= MaxTime; i++)
	{
		if (der.get_coeff(MaxTime) < 0)
		{
			now_a = now_b = false;
			if ((MaxTime-i) % 2 == 0)
				now_a = !now_a;
		}
		else
		{
			now_a = now_b = true;
			if ((MaxTime - i) % 2 == 0)
				now_a = !now_a;
		}
		if (now_a != formal_a)ans_amount++;
		if (now_b != formal_b)ans_amount--;
		formal_a = now_a;
		formal_b = now_b;
	}
	//std::cout << "ans_amount"<<ans_amount<<std::endl;
	return ans_amount;
}
double Poly::newton(double x0)
{
	int time = 100000;
	double eps = 0.0000001;
	while (time--)
	{//如果导数等于 0 怎么办....
		x0 -= this->get_ans(x0) / this->get_derivative_value(x0);
		if (fabs(this->get_ans(x0)) < eps) return x0;
	}
	return x0;
}