/*
 * circularBuffer.h
 *
 *  Created on: 2024��1��13��
 *      Author: wu
 */

#ifndef SRC_CIRCULARBUFFER_H_
#define SRC_CIRCULARBUFFER_H_

typedef struct {
    u32* arr;
    //arr�±�
    int front;
    int rear;
    //�ɴ��Ԫ�ظ���
    int capacity;


} Queue;

Queue* QueueCreate(int k);
bool QueueIsEmpty(Queue* obj);
bool QueueIsFull(Queue* obj);
bool QueueEnQueue(Queue* obj, u32 value);
bool QueueDeQueue(Queue* obj);
u32 QueueFront(Queue* obj);
u32 QueueRear(Queue* obj);
void QueueFree(Queue* obj);

#endif /* SRC_CIRCULARBUFFER_H_ */
