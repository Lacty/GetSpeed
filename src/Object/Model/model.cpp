
#include "../../MyLib/graph.h"
#include "cinder/Json.h"
#include "model.h"
#include <sstream>


Model::Model(const std::string& path) {
  std::ostringstream json_path;
  json_path << "Model/" << path << ".json";

  // Json����f�[�^�擾
  JsonTree data(loadAsset(json_path.str()));


  //-------------------------------------------------------
  // ���C���[�t���[���̏��

  // ���_�f�[�^�̐����擾
  int Vertex_Num = data["vertex_num"].getValue<int>();

  // ���_�f�[�^�̎擾
  std::vector<Vec3f> v;
  for (int i = 0; i < Vertex_Num; ++i) {
    std::ostringstream path;
    path << "v" << i;
    v.push_back({ Vec3f(data[path.str()]["x"].getValue<float>(),
                        data[path.str()]["y"].getValue<float>(),
                        data[path.str()]["z"].getValue<float>()) });
  }

  // ���C���[�̐F���擾
  ColorA wire_color(data["wire_color"]["r"].getValue<float>(),
                    data["wire_color"]["g"].getValue<float>(),
                    data["wire_color"]["b"].getValue<float>(),
                    data["wire_color"]["a"].getValue<float>());


  // Face(�|���S��)�̐����擾
  int Face_Num = data["face_num"].getValue<int>();

  // Face(�|���S��)�̒��_���W���擾
  for (int i = 0; i < Face_Num; ++i) {
    std::ostringstream path;
    path << "f" << i;
    faces.push_back({ { Vec3f(v[data[path.str()]["v1"].getValue<int>()]) },
                      { Vec3f(v[data[path.str()]["v2"].getValue<int>()]) },
                      { Vec3f(v[data[path.str()]["v3"].getValue<int>()]) },
                      { wire_color } });
  }


  //-------------------------------------------------------
  // Mesh�̏��

  // �|���S���̒��_���W���擾
  std::vector<Vec3f> vertices;
  for (int i = 0; i < Face_Num; ++i) {
    vertices.push_back({ Vec3f(faces[i].v1) });
    vertices.push_back({ Vec3f(faces[i].v2) });
    vertices.push_back({ Vec3f(faces[i].v3) });
  }
  
  // ���_���W�̓o�^
  m_mesh.appendVertices(&vertices[0], vertices.size());


  // ���_�F���擾
  std::vector<ColorA> color;
  for (int i = 0; i < Vertex_Num; ++i) {
    std::ostringstream path;
    path << "c" << i;
    color.push_back({ ColorA(data[path.str()]["r"].getValue<float>(),
                             data[path.str()]["g"].getValue<float>(),
                             data[path.str()]["b"].getValue<float>(),
                             data[path.str()]["a"].getValue<float>()) });
  }

  // �|���S���̒��_�F�����擾
  std::vector<ColorA> colors;
  for (int i = 0; i < Face_Num; ++i) {
    std::ostringstream path;
    path << "vc" << i;
    colors.push_back({ color[data[path.str()]["c1"].getValue<int>()] });
    colors.push_back({ color[data[path.str()]["c2"].getValue<int>()] });
    colors.push_back({ color[data[path.str()]["c3"].getValue<int>()] });
  }

  // ���_�F��o�^
  m_mesh.appendColorsRgba(&colors[0], colors.size());


  // �|���S�������ԍ����
  std::vector<uint32_t> indices;

  // Face_Num(�|���S���̐�) * 3 => �|���S�����ꂼ��̒��_���𑫂�������
  for (int i = 0; i < (Face_Num * 3); ++i) {
    indices.push_back(i);
  }

  // �����ԍ���o�^
  m_mesh.appendIndices(&indices[0], indices.size());
}

TriMesh& Model::get() {
  return m_mesh;
}

void Model::drawWire() const {
  for (auto& face : faces) {
    ly::drawLine(face.v1, face.v2, face.color);
    ly::drawLine(face.v2, face.v3, face.color);
    ly::drawLine(face.v3, face.v1, face.color);
  }
}