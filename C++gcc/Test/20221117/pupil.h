class Pupil : public student
{
public:
    virtual void study(); //把学习设置为虚函数
};
void Pupil::study()
{
    cout << "学习语数外。" << endl;
    return;
}