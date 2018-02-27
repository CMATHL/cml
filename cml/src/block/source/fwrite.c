int
FUNCTION(cml_block, fread)(FILE *stream, TYPE(cml_block) *b)
{
        size_t n = b->size;

        ATOMIC *data = b->data;

        size_t items = fread(data, MULTIPLICITY * sizeof(ATOMIC), n, stream);

        if (items != n)
        {
                CML_ERROR("fread failed", CML_EFAILED);
        }

        return 0;
}


int
FUNCTION(cml_block, fwrite)(FILE *stream, const TYPE(cml_block) *b)
{
        size_t n = b->size;

        ATOMIC *data = b->data;

        size_t items = fwrite(data, MULTIPLICITY * sizeof(ATOMIC), n, stream);

        if (items != n)
        {
                CML_ERROR("fwrite failed", CML_EFAILED);
        }

        return 0;
}

int
FUNCTION(cml_block, raw_fread)(FILE *stream, ATOMIC *data,
                               const size_t n, const size_t stride)
{
        if (stride == 1)
        {
                size_t items = fread(data, MULTIPLICITY * sizeof(ATOMIC), n, stream);

                if (items != n)
                {
                        CML_ERROR("fread failed", CML_EFAILED);
                }
        }
        else
        {
                size_t i;

                for (i = 0; i < n; i++)
                {
                        size_t item = fread(data + MULTIPLICITY * i * stride,
                                            MULTIPLICITY * sizeof(ATOMIC), 1, stream);
                        if (item != 1)
                        {
                                CML_ERROR("fread failed", CML_EFAILED);
                        }
                }
        }

        return CML_SUCCESS;
}

int
FUNCTION(cml_block, raw_fwrite)(FILE *stream, const ATOMIC *data,
                                const size_t n, const size_t stride)
{
        if (stride == 1)
        {
                size_t items = fwrite(data, MULTIPLICITY * sizeof(ATOMIC), n, stream);

                if (items != n)
                {
                        CML_ERROR("fwrite failed", CML_EFAILED);
                }
        }
        else
        {
                size_t i;

                for (i = 0; i < n; i++)
                {
                        size_t item = fwrite(data + MULTIPLICITY * i * stride,
                                             MULTIPLICITY * sizeof(ATOMIC),
                                             1, stream);
                        if (item != 1)
                        {
                                CML_ERROR("fwrite failed", CML_EFAILED);
                        }
                }
        }

        return CML_SUCCESS;
}
