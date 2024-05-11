#include "bomb.h"
#include "GameSetting.h"

Bomb::Bomb()
{
    //将所有爆炸pixmap放入数组
    for(int i = 0;i <= GameSetting::bombPicNum;i++){
        QString str = QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }

    //当前播放图片下标
    m_index=0;

    //播放爆炸间隔记录
    m_Recoder=0;
}

void Bomb::updateInfo()
{
    m_Recoder++;

    //如果记录爆炸的实际未达到爆炸间隔 return
    if(m_Recoder<GameSetting::bombCutInterval){
        return;
    }

    //重置记录
    m_Recoder = 0;

    //切换爆炸图片
    m_index++;

    if(m_index>GameSetting::bombPicNum-1)
    {
        m_index = 0;
        m_Free = true;
    }
}
