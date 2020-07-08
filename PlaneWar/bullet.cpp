#include "bullet.h"

Bullet::Bullet()
{
    //加载资源
    m_Bullet.load(BULLET_PATH);

    //子弹坐标
    m_X = (GAME_WIDTH - m_Bullet.width())*0.5;
    m_Y = GAME_HEIGHT;

    //子弹状态 默认空闲
    m_Free = true;

    //子弹速度
    m_Speed = BULLET_SPEED;

    //子弹边框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
}

void Bullet::updatePosition()
{
    //空闲下的子弹，不需要计算坐标
    if(m_Free){
        return;
    }

    //子弹向上移动
    m_Y-= m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    if(m_Y <= -m_Rect.height())
    {
        m_Free = true;
    }
}
