/*
 * circluarBuffer.cc
 *
 *  Created on: 2024��1��13��
 *      Author: wu
 */
#include "headers.h"
#include "circularBuffer.h"

Queue* QueueCreate(int k) {
    //��̬���ٽṹ��
    Queue* obj = (Queue*)malloc(sizeof(Queue));
    //��������
    obj->capacity = k;
    //��̬���ٽṹ���е����飬�࿪һ���ռ���������
    obj->arr = (u32*)malloc(sizeof(int)*(obj->capacity+1));
    obj->front = obj->rear = 0;


    return obj;
}


bool QueueIsEmpty(Queue* obj) {
    return obj->front == obj->rear;


}


bool QueueIsFull(Queue* obj) {
    return (obj->rear+1)%(obj->capacity+1) == obj->front;
}


bool QueueEnQueue(Queue* obj, u32 value) {
    //�����в����Ų���
	assert(!QueueIsFull(obj));
    if(!QueueIsFull(obj)){
        obj->arr[obj->rear] = value;
        obj->rear = (obj->rear+1)%(obj->capacity+1);
        return true;
    }else{
        return false;
    }
}


bool QueueDeQueue(Queue* obj) {
    //�����в�Ϊ�ղ�ɾ��
	assert(!QueueIsEmpty(obj));
    if(!QueueIsEmpty(obj)){
        obj->front = (obj->front+1)%(obj->capacity+1);
        return true;
    }else{
        return false;
    }
}


u32 QueueFront(Queue* obj) {
    //�����в�Ϊ�ջ�ȡ����Ϊ�շ���-1
	assert(!QueueIsEmpty(obj));
    if(!QueueIsEmpty(obj)){
        return obj->arr[obj->front];
    }else{
        return -1;
    }
}


u32 QueueRear(Queue* obj) {
        //�����в�Ϊ�ջ�ȡ����Ϊ�շ���-1
	assert(!QueueIsEmpty(obj));
    if(!QueueIsEmpty(obj)){
        return obj->arr[(obj->rear+obj->capacity)%(obj->capacity+1)];
    }else{
        return -1;
    }
}



void QueueFree(Queue* obj) {
    free(obj->arr);
    free(obj);
}
