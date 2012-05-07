#include "Triangle.h"

Triangle::Triangle()
{

	
		Verts.push_back (glm::vec3 (0 , 1.0 , 0));
		Verts.push_back (glm::vec3 (-1.0 , -1.0 , 0));
		Verts.push_back (glm::vec3 (1.0 , -1.0 , 0));
		

		programID = LoadShader ("VertexShader.vert" , "FragmentShader.frag");
	
}

void Triangle::Load()
{
//	ZRot = 0;


	glBindBuffer (GL_ARRAY_BUFFER , Buffer); // bindings
	glBufferData (GL_ARRAY_BUFFER , Verts.size()*sizeof(glm::vec3) , &Verts[0] , GL_STATIC_DRAW); // bindings

} // Simple so far.

void Triangle::Draw()
{
	

	glPushMatrix(); // push the matrix

	glUseProgram (programID); // use the shader

	glEnableVertexAttribArray (0); // enable stuff

		glBindBuffer (GL_ARRAY_BUFFER , Buffer); // bind stuff

		glVertexAttribPointer (
			 0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			 3,                  // size
			 GL_FLOAT,           // type
			 GL_FALSE,           // normalized?
		     0,                  // stride
		     (void*)0            // array buffer offset
			);

		glDrawArrays (GL_TRIANGLES , 0 , 3); // draw it!

	glDisableVertexAttribArray (0); // disable stuff
	glPopMatrix(); // pop the matrix

}

void Triangle::LoadMatrix()
{
	
 /*   // Get a handle for our "MVP" uniform
        MatrixID = glGetUniformLocation(programID, "MVP");

        // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
        Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
        // Camera matrix
        View       = glm::lookAt(
                                                                glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
                                                                glm::vec3(0,0,0), // and looks at the origin
                                                                glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                                                   );
        // Model matrix : an identity matrix (model will be at the origin)
        Model      = glm::mat4(1.0f);
        // Our ModelViewProjection : multiplication of our 3 matrices
        MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around*/

}

GLuint Triangle::LoadShader (const char * vertex_file_path,const char * fragment_file_path)
{
	 // Create the shaders
        GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

        // Read the Vertex Shader code from the file
        std::string VertexShaderCode;
        std::ifstream VertexShaderStream (vertex_file_path);
        if(VertexShaderStream.is_open()){
                std::string Line = "";
                while(getline(VertexShaderStream, Line))
                        VertexShaderCode += "\n" + Line;
                VertexShaderStream.close();
        }

        // Read the Fragment Shader code from the file
        std::string FragmentShaderCode;
        std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
        if(FragmentShaderStream.is_open()){
                std::string Line = "";
                while(getline(FragmentShaderStream, Line))
                        FragmentShaderCode += "\n" + Line;
                FragmentShaderStream.close();
        }



        GLint Result = GL_FALSE;
        int InfoLogLength;



        // Compile Vertex Shader
        printf("Compiling shader: %s\n", vertex_file_path);
        char const * VertexSourcePointer = VertexShaderCode.c_str();
        glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
        glCompileShader(VertexShaderID);

        // Check Vertex Shader
        glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
        glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
        std::vector<char> VertexShaderErrorMessage(InfoLogLength);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);




        // Compile Fragment Shader
        printf("Compiling shader: %s\n", fragment_file_path);
        char const * FragmentSourcePointer = FragmentShaderCode.c_str();
        glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
        glCompileShader(FragmentShaderID);

        // Check Fragment Shader
        glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
        glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);




        // Link the program
        fprintf(stdout, "Linking program\n");
        GLuint ProgramID = glCreateProgram();
        glAttachShader(ProgramID, VertexShaderID);
        glAttachShader(ProgramID, FragmentShaderID);
        glLinkProgram(ProgramID);

        // Check the program
        glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
        glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
        std::vector<char> ProgramErrorMessage( std::max(InfoLogLength, int(1)) );
        glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);


        glDeleteShader(VertexShaderID);
        glDeleteShader(FragmentShaderID);

        return ProgramID;
}