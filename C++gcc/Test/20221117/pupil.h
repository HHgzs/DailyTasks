class Pupil : public student
{
public:
    virtual void study(); //��ѧϰ����Ϊ�麯��
};
void Pupil::study()
{
    cout << "ѧϰ�����⡣" << endl;
    return;
}