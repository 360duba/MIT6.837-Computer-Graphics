#include "MatrixStack.h"

MatrixStack::MatrixStack(){
	// �õ�λ�����ʼ�������ջ��
	m_matrices.push_back(Matrix4f::identity());
}

void MatrixStack::clear(){
	// �ָ�Ϊ��������λ����
	m_matrices.clear();
	m_matrices.push_back(Matrix4f::identity());
}

Matrix4f MatrixStack::top(){
	// ����ջ��
	return m_matrices.back();
}

void MatrixStack::push( const Matrix4f& m ){
	//��m�����ջ��
	//���Ķ�ջӦ����OpenGL���壺
	//�µĶ���Ӧ���ǾɵĶ�������m
	Matrix4f newTop = m_matrices.back() * m;
	m_matrices.push_back(newTop);
}

void MatrixStack::pop(){
	// �Ӷ�ջ��ɾ������Ԫ��
	m_matrices.pop_back();
}


